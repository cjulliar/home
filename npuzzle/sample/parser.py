import sample
import sys

def npuzzle_parser(tokens):

	print (tokens)

	for token in tokens:
		exit = False
		for caracs in token:
			i = 0
			if exit: break
			for carac in caracs:
				if (caracs[i] == '#'):
					exit = True
					break
				print(caracs[i])
				i = i + 1
	
	for token in tokens:
		for number in token:
			if not number.isnumeric():
				print ('file not valaible')
				sys.exit()



	start_frame = tokens
	return start_frame