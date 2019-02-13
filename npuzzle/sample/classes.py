import time
import sample

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

class Directions:
	LEFT = Vector2(-1, 0)
	RIGHT = Vector2(1, 0)
	UP = Vector2(0, -1)
	DOWN = Vector2(0, 1)
	ALL = [UP, DOWN, LEFT, RIGHT]
	PRINT = {
				Vector2(0, 0) : 'start',
				UP : 'D',
				DOWN : 'U',
				LEFT : 'R',
				RIGHT : 'L'
			}

class Tile:
	"""
		The goal value si meant to be assigned once and stay untouched.
	"""
	def __init__(self, value = None, goal = None):
		self.value = value
		self.goal = goal
	
	def __repr__(self):
		str_ = '[ {}  -->{}]'.format(self.value, str(self.goal))
		return str_
	
	def __str__(self):
		if len(str(self.value)) > 1:
			str_ = '[ {} ]'.format(self.value)
		else:
			str_ = '[  {} ]'.format(self.value)
		return str_

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
		self._g = g
		self._h = 0
		self._f = g
		self.links = [parent] if parent is not None else []
		self.direction = Vector2(0, 0)
	
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
	def g(self):
		return self._g
	
	@g.setter
	def g(self, g):
		self._g = g
		self._f = self._h + g

	@property
	def f(self):
		return self._f
	
	def add_link(self, link):
		if not link in self.links:
			self.links.append(link)

class Solution:
	"""
		Holds all the relevant informations necessary to print out the solution
		Also, prints out the solution.
	"""
	def __init__(self, opened, closed, select_count, end):
		self.time_complexity = select_count
		self.size_complexity = len(opened) + len(closed)
		self.total_moves = end.g
		self.sequence = []
		state = end
		while state:
			self.sequence.insert(0, state)
			state = state.parent
	
	#def print_windows(self, fenetre, image):
		#for i, state in enumerate(self.sequence[1:]):
			#print (state.frame)

			#sample.npuzzle_image(fenetre, image, state.frame)
			#time.sleep(1)
		#print(f'\nTOTAL MOVES : {self.total_moves}\n')
		#print(f'time complexity : {self.time_complexity}')
		#print(f'size complexity : {self.size_complexity}')

	def print_out(self, verbose = False):
		for i, state in enumerate(self.sequence[1:]):
			if verbose:
				print(f'{i}.')
				print(state.frame)
			else:
				print(f'{i}.\t', Directions.PRINT[state.direction])
		print(f'\nTOTAL MOVES : {self.total_moves}\n')
		print(f'time complexity : {self.time_complexity}')
		print(f'size complexity : {self.size_complexity}')

