import sys

my_file = sys.argv[1]

contents = ""
try:
   	file = open(my_file, 'r')
except IOError:
    print ('cannot open', my_file)
    sys.exit()
else:
    contents = file.read()



lines = contents.split("\n")
tokens = []
for line in lines:
	line = line.split(" ")
	tokens.append(line)

#test numeric value
for token in tokens:
	for number in token:
		if not number.isnumeric():
			print ('file not valaible')
			sys.exit()


print(tokens)





file.close()