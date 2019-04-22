from npuzzle.classes import Vector2

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
