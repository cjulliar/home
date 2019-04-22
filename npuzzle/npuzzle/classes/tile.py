class Tile:
	"""
		The goal value si meant to be assigned once and stay untouched.
	"""
	def __init__(self, value = None, goal = None):
		self.value = value
		self.goal = goal
		self._str = None
	
	def __repr__(self):
		if self._str is None:
			self._str = '[ {}  -->{}]'.format(self.value, str(self.goal))
		return self._str
	
	def __str__(self):
		if len(str(self.value)) > 1:
			str_ = '[ {} ]'.format(self.value)
		else:
			str_ = '[  {} ]'.format(self.value)
		return str_
