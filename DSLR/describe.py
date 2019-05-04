#!/usr/bin/env python3

import lexer
import sys
from prettytable import PrettyTable
import math
# python3 -m pip install --user --upgrade pip
# python3 -m pip install --user PrettyTable

def init_tab(datas):
	title = []
	for line in datas[0][5:]:
		title.append(line)
	title[0] = ""
	tab = PrettyTable(title)
	tab.padding_width = 1
	return tab

def count_features(datas, tab):
	count_f = [0] * 14
	for line in datas[1:]:
		for i, feature in enumerate(line[5:]):
			if feature:
				count_f[i] += 1
	count_f[0] = "count"
	tab.add_row(count_f)
	return tab, count_f

def mean_features(datas, tab, count_f):
	mean_f = [float(0)] * 13
	for line in datas[1:]:
		for i, feature in enumerate(line[6:]):
			if feature:
				mean_f[i] += float(feature)
	for i, value in enumerate(mean_f[0:]):
		div = float(count_f[i+1])
		mean_f[i] = round(value / div,2)
	mean_f.reverse()
	mean_f.append("mean")
	mean_f.reverse()
	tab.add_row(mean_f)
	return tab, mean_f

def variance_features(datas, tab, count_f, mean_f):
	var_f = [float(0)] * 13
	s_var_f = [float(0)] * 13
	for line in datas[1:]:
		for i, feature in enumerate(line[6:]):
			if feature:
				var_f[i] += (float(feature) - float(mean_f[i+1]))**2
	for i, value in enumerate(var_f[0:]):
		total = float(count_f[i+1])
		var_f[i] = round(value / total,2)
		s_var_f[i] = round(value / (total + 1),2)
	var_f.reverse()
	var_f.append("variance")
	var_f.reverse()
	tab.add_row(var_f)
	return tab, var_f, s_var_f

def std_features(datas, tab, var_f, s_var_f):
	std_f = [float(0)] * 14
	ssd_f = [float(0)] * 14
	for i, val in enumerate(std_f[1:]):
		tmp = math.sqrt(var_f[i+1])
		s_tmp = math.sqrt(s_var_f[i])
		std_f[i+1] = round(tmp,3)
		ssd_f[i+1] = round(s_tmp,3)
	std_f[0] = "std"
	tab.add_row(std_f)
	ssd_f[0] = "ssd"
	tab.add_row(ssd_f)
	return tab

def min_features(datas, tab):
	min_f = [''] * 13
	for line in datas[1:]:
		for i, feature in enumerate(line[6:]):
			if feature and (not min_f[i] or float(feature) < min_f[i]):
				min_f[i] = round(float(feature),2)
	min_f.reverse()
	min_f.append("min")
	min_f.reverse()
	tab.add_row(min_f)
	return tab, min_f

def sort_list(datas, num_feature):
	sort_l = []
	for i, line in enumerate(datas[1:]):
		for feature in line[num_feature:num_feature+1]:
			if feature:
				sort_l.append(float(feature))
	return sorted(sort_l)

def perce_features(datas, tab, count_f):
	list_sorted = []
	tf_f = []
	f_f = []
	sf_f = []
	tf_f.append("25%")
	f_f.append("50%")
	sf_f.append("75%")
	i = 6
	while i < 19:
		list_sorted.append(sort_list(datas, i))
		i += 1
	for y, feature in enumerate(list_sorted):
		i = 0
		while i / count_f[y+1] <= 0.25:
			i += 1
			tmp = feature[i]
		tf_f.append(round(tmp,2))
		if count_f[y+1] % 2 == 1:
			i = int((count_f[y+1] + 1) / 2)
			f_f.append(round(feature[i],2))
		else:
			i = int(count_f[y+1] / 2 + 1)
			m = (feature[int(count_f[y+1] / 2)]+feature[i])/2
			f_f.append(round(m,2))
		while i / count_f[y+1] <= 0.75:
			i += 1
			tmp = feature[i]
		sf_f.append(round(tmp,2))
	tab.add_row(tf_f)
	tab.add_row(f_f)
	tab.add_row(sf_f)

	return tab, tf_f, sf_f


def max_features(datas, tab):
	max_f = [''] * 13
	for line in datas[1:]:
		for i, feature in enumerate(line[6:]):
			if feature and (not max_f[i] or float(feature) > max_f[i]):
				max_f[i] = round(float(feature),2)
	max_f.reverse()
	max_f.append("max")
	max_f.reverse()
	tab.add_row(max_f)
	return tab, max_f

def range_features(datas, tab, min_f, max_f):
	range_f = [0] * 14
	i = 1
	while i < 14:
		range_f[i] = round(float(max_f[i]) - float(min_f[i]),2)
		i += 1
	range_f[0] = "range"
	tab.add_row(range_f)
	return tab

def iqr_features(datas, tab, tf_f, sf_f):
	iqr_f = [0] * 14
	iqr_f[0] = "iqr"
	i = 1
	while i < 14:
		iqr_f[i] = round(float(sf_f[i]) - float(tf_f[i]),2)
		i += 1
	tab.add_row(iqr_f)
	return tab

def describe(argv):
	try :
		datas = lexer.datas(sys.argv[1])
	except :
		print ("Failed to read the file.")
		exit();

	tab = init_tab(datas)
	tab, count_f = count_features(datas, tab)
	tab, mean_f = mean_features(datas, tab, count_f)
	tab, var_f, s_var_f = variance_features(datas, tab, count_f, mean_f)
	tab = std_features(datas, tab, var_f, s_var_f)
	tab, min_f = min_features(datas, tab)
	tab, tf_f, sf_f = perce_features(datas, tab, count_f)
	tab, max_f = max_features(datas, tab)
	tab = range_features(datas, tab, min_f, max_f)
	tab = iqr_features(datas, tab, tf_f, sf_f)
	print(tab)

















if __name__ == '__main__':
    describe(sys.argv[1:])