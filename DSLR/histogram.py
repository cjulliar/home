#!/usr/bin/env python3

import lexer
import matplotlib.pyplot as plt
import numpy as np
import sys
#import seaborn as sns
# python3.4 -m pip install --user seaborn

def min_features(datas):
	min_f = [''] * 13
	for line in datas[1:]:
		for i, feature in enumerate(line[6:]):
			if feature and (not min_f[i] or float(feature) < min_f[i]):
				min_f[i] = round(float(feature),2)
	return min_f

def max_features(datas):
	max_f = [''] * 13
	for line in datas[1:]:
		for i, feature in enumerate(line[6:]):
			if feature and (not max_f[i] or float(feature) > max_f[i]):
				max_f[i] = round(float(feature),2)
	return max_f

def feature_house(datas, num_feature):
	feat_house = []
	feat_ravenclaw = []
	feat_slytherin = []
	feat_gryffindor = []
	feat_hufflepuff = []
	for i, line in enumerate(datas):
		for y, feature in enumerate(line[num_feature:num_feature+1]):
			if line[1] == "Ravenclaw":
				feat_ravenclaw.append(feature)
			elif line[1] == "Slytherin":
				feat_slytherin.append(feature)
			elif line[1] == "Gryffindor":
				feat_gryffindor.append(feature)
			elif line[1] == "Hufflepuff":
				feat_hufflepuff.append(feature)
	feat_house.append(feat_ravenclaw)
	feat_house.append(feat_slytherin)
	feat_house.append(feat_gryffindor)
	feat_house.append(feat_hufflepuff)
	return feat_house

def display(fh, name):
	bins = [x + 0.5 for x in range(int(min_f), int(max_f))]
	plt.hist(fh[0], histtype = 'stepfilled', color = 'green', alpha = 0.25, label = 'Gryff')
	plt.hist(fh[1], histtype = 'stepfilled', color = 'blue', alpha = 0.25, label = 'Slith')
	plt.hist(fh[2], histtype = 'stepfilled', color = 'red', alpha = 0.25, label = 'Huffle')
	plt.hist(fh[3], histtype = 'stepfilled', color = 'yellow', alpha = 0.25, label = 'Ravenc')
	plt.xlabel('Mark')
	plt.ylabel('Students')
	plt.title('Histogram of '+ name)
	#plt.axis([-180, 280, 0, 100])

	plt.show()

def histogram(argv):
	try :
		datas = lexer.datas(sys.argv[1])
	except :
		print ("Failed to read the file.")
		exit();
#	min_f = min_features(datas)
#	max_f = max_features(datas)
#	print (min_f[11])
#	print (max_f[11])
	f_h = feature_house(datas, 17)
#	display (feat_house, datas[0][17], min_f[11], max_f[11])



	print(plt.style.available[:6])

	# Notez la taille de la figure
	fig = plt.figure(figsize=(12,8))
	for i in range(6):
		# On peut ajouter des sous graphes ainsi
		fig.add_subplot(3,2,i+1)
#		display(f_h,datas[0][17])
		plt.style.use(plt.style.available[i])
		plt.plot(x, y)
		# Pour ajouter du texte
		plt.text(s=plt.style.available[i], x=5, y=2, color='red')


		








#	i = 6
#	while i < 19:
#		i += 1
#		feat_house = feature_house(datas, i)
	


	
	# ax = [0, 1, 2, 3, 4, 5, 6]
	# np.random.seed(0)
	# n_bins = 10
	# x = np.random.randn(1000, 3)
	# fh = feature_house(datas, 18)

	# fig, axes = plt.subplots(nrows=5, ncols=4)
	# ax = axes.flatten()

	# colors = ['red', 'tan', 'lime']
	# #ax0.hist(x, n_bins, normed=1, histtype='bar', color=colors, label=colors)
	# ax[0].hist(fh[0], histtype = 'stepfilled', color = 'green', alpha = 0.25, label = 'Gryff')
	# ax[0].hist(fh[1], histtype = 'stepfilled', color = 'blue', alpha = 0.25, label = 'Slith')
	# ax[0].hist(fh[2], histtype = 'stepfilled', color = 'red', alpha = 0.25, label = 'Huffle')
	# ax[0].hist(fh[3], histtype = 'stepfilled', color = 'yellow', alpha = 0.25, label = 'Ravenc')
	# ax[0].legend(prop={'size': 10})
	# ax[0].set_title('Histogram of '+ datas[0][18])


	# ax[1].hist(x, n_bins, normed=1, histtype='bar', stacked=True)
	# ax[1].set_title('stacked bar')

	# ax[2].hist(x, n_bins, histtype='step', stacked=True, fill=False)
	# ax[2].set_title('stack step (unfilled)')

	# # Make a multiple-histogram of data-sets with different length.
	# x_multi = [np.random.randn(n) for n in [10000, 5000, 2000]]
	# ax[3].hist(x_multi, n_bins, histtype='bar')
	# ax[3].set_title('different sample sizes')

	# fig.tight_layout()
	# plt.show()



	# x1 = np.linspace(0.0, 5.0)
	# y1 = np.cos(2 * np.pi * x1) * np.exp(-x1)
	
	# x2 = np.linspace(0.0, 2.0)
	# y2 = np.cos(2 * np.pi * x2)	
	
	# x3 = np.linspace(0.0, 4.0)
	# y3 = np.cos(2 * np.pi * x3)	
	
	# x4 = np.linspace(-2.0, 2.0)
	# y4 = np.cos(2 * np.pi * x4)	
	
	# x5 = np.linspace(-10.0, 20.0)
	# y5 = np.cos(2 * np.pi * x5)

	# i = 6
	# while i < 7:
	# 	#p = i - 5
	# 	fh = feature_house(datas, i)
	# 	plt.subplot(8, 4, i)

	# 	plt.hist(fh[0], histtype = 'stepfilled', color = 'green', alpha = 0.25, label = 'Gryff')
	# 	plt.hist(fh[1], histtype = 'stepfilled', color = 'blue', alpha = 0.25, label = 'Slith')
		
	# 	#plt.legend(prop={'size': 10})
	# 	plt.title('Histogram of '+ datas[0][i])
	# 	i += 1
	

	# plt.subplot(432)
	# plt.plot(x2, y2, '.-')
	# plt.xlabel('time (s)')
	# plt.ylabel('Undamped')

	# plt.subplot(433)
	# plt.plot(x3, y4, '.-')
	# plt.xlabel('3 (s)')
	# plt.ylabel('3 ---------- stop')


	plt.show()
















if __name__ == '__main__':
    histogram(sys.argv[1:])