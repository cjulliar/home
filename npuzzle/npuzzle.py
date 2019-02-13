#!/usr/bin/env python3

import sys
import windows
import sample
import random

def option_parser(args):
	options = {}
	options['strategy'] = lambda state : state.h
	#options['strategy'] = lambda state : state.f
	options['verbose'] = True
	options['verbose'] = False
	options['windows'] = False
	return options

def main(puzzle, options):
	try:
		with open(puzzle, 'r') as f:
			raw_text = f.read()
	except:
		print('Could not open file ({}). Program closing.'.format(input_path))
		sys.exit()
	tokens = sample.npuzzle_lemmatizer(raw_text)
	tokens = sample.npuzzle_parser(tokens)
	start_frame = sample.npuzzle_map(tokens)
	#affichage de l'image au depart
	#if options['windows']:
		#fenetre, image = sample.npuzzle_windows(start_frame)
		#sample.npuzzle_image(fenetre, image, start_frame)
	start_state, goal_state, solvable = sample.npuzzle_init_states(start_frame)
	if solvable:
		solution = sample.npuzzle_solver(start_state, goal_state, \
			#sample.hamming_distance, options['strategy'])
			sample.linear_conflict, options['strategy'])
			#sample.manhattan_distance, options['strategy'])
		if options['windows']:
			
			#solution.print_windows(fenetre, image)
				
			sample.npuzzle_image(solution)
		else:
			solution.print_out(verbose = options['verbose'])
	else:
		print(start_state.frame)
		print('This puzzle is impossible to solve !')

if __name__ == '__main__':
	if len(sys.argv) < 2:
		print('Usage : ./npuzzle.py input')
		sys.exit()
	options = option_parser(sys.argv)
	main(sys.argv[1], options)
