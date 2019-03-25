#!/usr/bin/env python3


from sampling.lexer import lexer
import sys

data = open("sampling/data", "r")
datas = lexer(data)
print(datas)

data.close()