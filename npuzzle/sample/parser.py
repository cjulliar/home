import sample
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
				print ('file not valaible: only numbers are accepted')
				return False
	return True

def all_number(tokens):
	"""Check if all number of puzzle are in tokens"""
	size = tokens[0][0]
	number_max = int(size)**2
	token_model = [i for i in range(number_max)]
	tokens_cpy = list(tokens)
	tokens_cpy[0] = ""
	for token in tokens_cpy:
		for num in token:
			try:
				token_model.remove(int(num))
			except:
				print ('file not valaible: invalid map')
				return False
	if token_model:
		print ('file not valaible: invalid map')
		return False
	
	return True

def aligned(tokens):
	"""Check if all lines have *size* number and *size* line"""
	size = tokens[0][0]
	l = -1
	for token in tokens:
		s = 0
		for num in token:
			s = s + 1
		if l == -1:
			if s > 1:
				print ('file not valaible: invalid map in line 1')
				return False
		elif s != int(size):
			print ('file not valaible: invalid map 2')
			return False
		l = l + 1
	if l != int(size):
		print ('file not valaible: invalid map 3')
		return False
	return True

def npuzzle_parser(tokens):
	tokens = delete_comments(tokens)
	if not is_number(tokens):
		sys.exit()
	if not all_number(tokens):
		sys.exit()
	if not aligned(tokens):
		sys.exit()
	start_frame = tokens
	return start_frame
