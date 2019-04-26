#!/usr/bin/env python3

import lexer

def precision():
    datas = lexer.datas()
    theta = lexer.thetas()

    my = 0
    for i, line in enumerate(datas):
    	n = i + 1
    	my += line[1]
    my /= n

    sse = 0
    ssr = 0
    for i, line in enumerate(datas):
    	fy = theta[0] + line[0] * theta[1]
    	sse += (fy - my) * (fy - my)
    	ssr +=  (line[1] - fy) * (line[1] - fy)
    sst = sse + ssr
    r2 = sse / sst
    print("the precision of the algorithm is:", r2)

if __name__ == '__main__':
    precision()
