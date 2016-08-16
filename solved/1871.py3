for i in range(int(input())):
	al, di = input().split('-')
	n1 = sum([(ord(a)-ord('A'))*b for a,b in zip(al,[26*26,26,1])])
	n2 = sum([(ord(a)-ord('0'))*b for a,b in zip(di,[1000,100,10,1])])
	if n1 - n2 >= -100 and n1 - n2 <= 100 :
		print("nice")
	else:
		print("not nice")