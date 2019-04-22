#!/usr/bin/env python3.6

import sys
import argparse
import npuzzle

def parse_from_file(args):
	try:
		with open(args.puzzle, 'r') as f:
			raw_text = f.read()
	except:
		print('Could not open file ({}). Program closing.'.format(args.puzzle))
		sys.exit()
	tokens = npuzzle.npuzzle_lexer(raw_text)
	tokens = npuzzle.npuzzle_parser(tokens)
	start_frame = npuzzle.npuzzle_map(tokens)
	return npuzzle.npuzzle_init_states(start_frame)

def generate_states(args):
	ok_puzzle = False
	while not ok_puzzle:
		tokens = npuzzle.generate_puzzle(args.size)
		start_frame = npuzzle.npuzzle_map(tokens)
		start_state, goal_state, solvable = npuzzle.npuzzle_init_states(start_frame)
		if args.u != solvable:
			ok_puzzle = True
	return start_state, goal_state, solvable
	
def export_puzzle(args, start_state, solvable):
	to_print = f'# solvable = {solvable}\n'
	to_print += f'{start_state.frame.size}\n'
	for i, row in enumerate(start_state.frame.tiles):
		for j, tile in enumerate(row):
			if j < len(row) - 1:
				to_print += f'{tile.value} '
			else:
				to_print += f'{tile.value}'
		if i < len(start_state.frame.tiles) - 1:
			to_print += '\n'
	print(to_print)

def main(parser):
	args = parser.parse_args()
	if 'puzzle' in vars(args).keys():
		start_state, goal_state, solvable = parse_from_file(args)
	elif 'size' in vars(args).keys():
		start_state, goal_state, solvable = generate_states(args)
		if args.output:
			export_puzzle(args, start_state, solvable)	
			sys.exit()
	else:
		parser.print_help()
		sys.exit()
	if solvable:
		solution = npuzzle.npuzzle_astar(start_state, goal_state, \
			npuzzle.HEURISTICS[args.heuristic], args.strategy)
		solution.print_out(simple = args.simple)
		if args.visual is not None:
			npuzzle.npuzzle_image(solution, args.visual)
	else:
		print(start_state.frame)
		print('This puzzle is impossible to solve !')

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description = 'Solves some n-puzzle.')
	subparsers = parser.add_subparsers()
	file_parser = subparsers.add_parser('file',
		help = 'Import puzzle from file')
	file_parser.add_argument('puzzle')
	generator_parser = subparsers.add_parser('generate',
		help = 'Generates a random puzzle.')
	generator_parser.add_argument('size', type = int,
		help = 'Choose size of the puzzle\'s side. An 8-puzzle has a size of 3')
	generator_parser.add_argument('-u', action = 'store_true',
		help = 'Forces the generated puzzle to be unsolvable')
	generator_parser.add_argument('-o', '--output', action = 'store_true',
		help = 'Prints the puzzle instead of solving it')
	parser.add_argument('-s', '--strategy', choices = ['greedy', 'uniform'],
		help = 'Choose search strategy between greedy and uniform. \
Defaults depends on puzzle\'s size')
	parser.add_argument('--heuristic', \
		choices = ['manhattan', 'linear_conflict', 'hamming'],
		default = 'linear_conflict',
		help = 'Choose heuristic between manhattan distance, manhattan \
distance corrected with linear conflicts, or hamming distance.')
	parser.add_argument('--simple', action = 'store_true',
		help = 'Prints the moves as UDLR instead of board states')
	parser.add_argument('-v', '--visual', type = int, metavar = 'freq',
		help = 'Makes it pretty. You can choose the time between each step\
(in milliseconds)')
	main(parser)
