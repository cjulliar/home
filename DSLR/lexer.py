#!/usr/bin/env python3

from string import *

def datas(file):
	data = open(file, "r")
	contents = data.read()
	lines = contents.split("\n")
	datas = []
	tmp_line = []
	for line in lines[0:]:
		if line:
			tmp = (line.split(","))
			tmp = [x for x in tmp ]
			datas.append(tmp)
	return datas