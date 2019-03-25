#!/usr/bin/env python3

def lexer(data):

	contents = data.read()
	lines = contents.split("\n")
	datas = []
	tmp_line = []
	for line in lines[1:]:
		if line:
			tmp = (line.split(","))
			tmp = [ int(x) for x in tmp ]
			datas.append(tmp)

	return datas