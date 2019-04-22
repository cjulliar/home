from npuzzle.classes import Directions

class Solution:
	"""
		Holds all the relevant informations necessary to print out the solution
		Also, prints out the solution.
	"""
	def __init__(self, size_complexity, select_count, end):
		self.time_complexity = select_count
		self.size_complexity = size_complexity
		self.total_moves = end.g
		self.sequence = []
		state = end
		g = state.g
		while state:
			del state.links
			self.sequence.append(state)
			state = state.parent
		self.sequence.reverse()
	
	def print_out(self, simple = False):
		for i, state in enumerate(self.sequence):
			if not simple:
				print(f'{i}.')
				print(state.frame)
			else:
				print(f'{i}.\t', Directions.PRINT[state.direction])
		print(f'\nTOTAL MOVES : {self.total_moves}\n')
		print(f'time complexity : {self.time_complexity}')
		print(f'size complexity : {self.size_complexity}')
