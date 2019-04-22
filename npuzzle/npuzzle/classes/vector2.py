class Vector2:
	"""
	"""
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def __str__(self):
		str_ = '({}, {})'.format(self.x, self.y)
		return str_

	def __hash__(self):
		return hash(str(self))

	def __eq__(self, other):
		if self.x == other.x and self.y == other.y:
			return True
		else:
			return False
	
	def __ne__(self, other):
		if self == other:
			return False
		else:
			return True
	
	def __add__(self, other):
		return Vector2(self.x + other.x, self.y + other.y)

	def __sub__(self, other):
		return Vector2(self.x - other.x, self.y - other.y)
