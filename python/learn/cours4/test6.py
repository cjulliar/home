print("En python, 0.1 * 3=")
print(0.1 * 3)

from fractions import Fraction

un_dixieme = Fraction(1, 10)
print(un_dixieme * 3)
print(float(un_dixieme * 3))


import random

print(random.randrange(1,10,1)) #1 inclus et 10 exclus

x = random.randint(1,10) #entre 1 et 10
while x != 10:
	print(x)
	x = random.randint(1,10)
print(x)

lst = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
print(random.choice(lst))
random.shuffle(lst)
print(lst)

#3 choix parmis une liste:
print(random.sample(lst, 3))