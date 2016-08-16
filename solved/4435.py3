gan = [1,2,3,3,4,10]
sau = [1,2,2,2,3,5,10]
for i in range(int(input())):
	g = sum([p*q for (p,q) in zip(gan,[int(s) for s in input().split()])])
	s = sum([p*q for (p,q) in zip(sau,[int(s) for s in input().split()])])
	print("Battle %d: " %(i+1),end="")
	if g > s :
		print("Good triumphs over Evil")
	elif g < s :
		print("Evil eradicates all trace of Good")
	else:
		print("No victor on this battle field")