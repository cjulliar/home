age = input("Quel est ton age ?\n")
print("Tu as donc",age,"ans")
if int(age) < 0:
	print("Tu ne peut pas être humain")
	print("est-tu sûr de ne pas t'être trompé ?")
elif int(age) == 23:
	print("et tu es stylé")