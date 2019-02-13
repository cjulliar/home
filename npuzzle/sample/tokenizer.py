def npuzzle_lemmatizer(raw_text):
	""" the process of converting a sequence of characters in list"""
	lines = raw_text.split("\n")
	tokens = []
	for line in lines:
		line = line.split()
		tokens.append(line)
	return tokens