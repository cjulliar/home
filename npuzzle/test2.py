class Checker:
	def __init__(self, y):
		self.__y = y
	
	def __hash__(self):
		return hash(self.__y)

	def __eq__(self, other):
		if self.__y == other:
			print('hooray')
			return True
		return False

a = 1
b = 1

c = set()
c.add(a)
d = Checker(b)

if d in c:
	print('yay')
else:
	print('nay')