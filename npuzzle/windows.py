import sys
import npuzzle

def option_parser(args):
	options = {}
	options['strategy'] = lambda state : state.h
	#options['strategy'] = lambda state : state.f
	options['verbose'] = True
	options['verbose'] = False
	options['windows'] = True
	return options


def wind(puzzle, options):
	npuzzle.main(puzzle, options)

if __name__ == '__main__':
	if len(sys.argv) < 2:
		print('Usage : ./npuzzle.py input')
		sys.exit()
	options = option_parser(sys.argv)
	wind(sys.argv[1], options)