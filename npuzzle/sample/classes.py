class Vector2:
	"""
	"""
	def __init__(self, x, y):
		self.x = x
		self.y = y
	
	def __str__(self):
		str_ = '({}, {})'.format(self.x, self.y)
		return str_

class Tile:
	"""
		Tiles can be initialized with or without starting coordinates.
		Coordinates can be updated in three different ways:
			- direct asignements to x and y
			- assigning new values to the Vector2 using (x, y) as a tuple
			- assigning a new Vector2 to coord
		The goal value si meant to be assigned once and stay untouched.
	"""
	def __init__(self, value = None, coord = None, goal = None):
		self.value = value
		if coord is not None:
			self._coord = coord
		else:
			self._coord = Vector2(0, 0)
		self.goal = goal
	
	def __repr__(self):
		str_ = '[ {}\t: {}->{}]'.format(self.value, str(self._coord), str(self.goal))
		return str_
	
	def __str__(self):
		if len(str(self.value)) > 1:
			str_ = '[ {} ]'.format(self.value)
		else:
			str_ = '[  {} ]'.format(self.value)
		return str_
	
	@property
	def x(self):
		return self._coord.x
	
	@x.setter
	def x(self, x):
		self._coord.x = x
	
	@property
	def y(self):
		return self._coord.y
	
	@y.setter
	def y(self, y):
		self._coord.y = y
	
	@property
	def coord(self):
		return self._coord
	
	@coord.setter
	def coord(self, new_coord):
		if isinstance(new_coord, tuple):
			self._coord.x = new_coord[0]
			self._coord.y = new_coord[1]
		else:
			self._coord = new_coord

class Frame:
	"""
		A Frame captures a state of the puzzle's tiles.
		When you want to generate linked states, one should use the
		Frame.copy method to get a copy of current frame, and then apply
		a movement.
	"""
	def __init__(self, size, tiles = None):
		self.size = size
		self._zero = None
		if tiles:
			self.tiles = tiles
		else:
			self.tiles = []
			for i in range(size):
				new_row = [Tile(coord = Vector2(j, i)) for j in range(size)]
				self.tiles.append(new_row)

	def __str__(self):
		str_ = 'Frame of size {}. Zero at {}\n'.format(self.size, self._zero)
		str_ += '\n'
		for row in self.tiles:
			for t in row:
				str_ += str(t)
			str_ += '\n'
		str_ += '\n'
		return str_

	@property
	def zero(self):
		return self._zero
	
	@zero.setter
	def zero(self, new_zero):
		if isinstance(new_zero, tuple):
			self._zero.x = new_coord[0]
			self._zero.y = new_coord[1]
		else:
			self._zero = new_zero
	
	def copy(self):
		tiles_copy = []
		for row in self.tiles:
			new_row = [tile for tile in row]
			tiles_copy.append(new_row)
		frame_copy = Frame(self.size, tiles = tiles_copy)
		frame_copy.zero = self.zero
		return frame_copy

class State:
	"""
		g : movement cost
		h : heuristic cost
		f : total cost (sum of g and h)
		Setting h value also updates f
		You can't directly update f
	"""
	def __init__(self, frame, parent, g):
		self.frame = frame
		self.parent = parent
		self.g = g
		self._h = None
		self._f = None
		self.links = [parent] if parent is not None else []
	
	def __str__(self):
		str_ = 'parent : {}\n'.format(repr(self.parent))
		str_ += 'links : {}\n'.format(self.links)
		str_ += 'g = {} | h = {} | f = {}\n'.format(self.g, self.h, self.f)
		str_ += str(self.frame)
		return str_
	
	@property
	def h(self):
		return self._h
	
	@h.setter
	def h(self, h):
		self._h = h
		self._f = self._g + h

	@property
	def f(self):
		return self._f
	
	def add_link(self, link):
		if not link in self.links:
			self.links.append(link)
