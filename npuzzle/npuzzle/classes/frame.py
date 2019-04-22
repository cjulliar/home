from npuzzle.classes import Tile, Vector2

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
		self._hash = None
		if tiles:
			self.tiles = tiles
		else:
			self.tiles = []
			for i in range(size):
				new_row = [Tile() for j in range(size)]
				self.tiles.append(new_row)

	def __str__(self):
		#str_ = 'Frame of size {}. Zero at {}\n'.format(self.size, self._zero)
		str_ = '\n'
		for row in self.tiles:
			for t in row:
				str_ += str(t)
				#str_ += repr(t)
			str_ += '\n'
		str_ += '\n'
		return str_
	
	def __hash__(self):
		if self._hash is None:
			self._hash = hash(str(self.tiles))
		return self._hash
	
	def __eq__(self, other):
		return hash(self) == hash(other)
			
	def __ne__(self, other):
		if self == other:
			return False
		else:
			return True

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
		frame_copy.zero = Vector2(self.zero.x, self.zero.y)
		return frame_copy
	
	def push(self, direction):
		coord_push = self.zero + direction
		zero_tile = self.tiles[self.zero.y][self.zero.x]
		self.tiles[self.zero.y][self.zero.x] = self.tiles[coord_push.y][coord_push.x]
		self.tiles[coord_push.y][coord_push.x] = zero_tile
		self.zero = coord_push
