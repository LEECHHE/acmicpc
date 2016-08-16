y = 0; k = 0
for i in range(int(input())):
	for j in range(9):
		yonsei, korea = [int(i) for i in input().split()]
		y += yonsei; k += korea;
	if y > k :
		print ("Yonsei")
	elif y < k :
		print ("Korea")
	else :
		print ("Draw")