tokens = [['300#n1'], ['6', '5', '3', '#commentaire'], ['8', '4', '7', '#la', 'aussi'], ['#', 'la', 'aussi'], ['1', '2', '0']]

for token in tokens:
	print (token)

parses = []

for token in tokens:
	parse = []
	exit = False
	for caracs in token:
		pars = []
		i = 0
		if exit: break
		for carac in caracs:
			if (caracs[i] == '#'):
				exit = True
				break
			print(caracs[i])
			i = i + 1
		parse.append(pars)
	parses.append(parse)

print(parses)