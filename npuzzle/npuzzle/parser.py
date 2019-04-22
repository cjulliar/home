import npuzzle
import sys

def delete_comments(tokens):
	"""Delete all comments"""
	tab = []
	for token in tokens:
		line = []
		exit = False
		for caracs in token:
			word = ""
			if exit: break
			for carac in caracs:
				if (carac == '#'):
					exit = True
					break
				word = word + carac
			if word:
				line.append(word)
		if line:
			tab.append(line)

	
	tokens = [x for x in tab if x != ['']]
	
	return (tokens)


def is_number(tokens):
	"""Check if all tokens are numbers"""
	for token in tokens:
		for number in token:
			if not number.isnumeric():
				print ('error: only numbers are accepted')
				return False
	return True

def is_format_puzzle(tokens, size):
	if size < 1:
		return False
	if len(tokens) != size:
		return False
	for t in tokens:
		if len(t) != size:
			return False
	return True

def all_number(tokens):
	"""Check if all number of puzzle are in tokens"""
	puzzle_size = int(tokens[0][0])
	number_max = puzzle_size ** 2
	token_model = [i for i in range(number_max)]
	for token_line in tokens[1:]:
		for num in token_line:
			try:
				token_model.remove(int(num))
			except:
				print ('error: invalid map')
				return False
	if token_model:
		print ('error: invalid map')
		return False
	return True

def npuzzle_parser(tokens):
	tokens = delete_comments(tokens)
	if not is_number(tokens):
		sys.exit()
	if not is_format_puzzle(tokens[1:], int(tokens[0][0])):
		print ('error: invalid map')
		sys.exit()
	if not all_number(tokens):
		sys.exit()
	start_frame = tokens
	return start_frame
