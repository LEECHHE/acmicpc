while True:
	randList = []
	N = int(raw_input())
	if N == 0 : break;
	else :
		zero = '00000000'
		while True:
			if N in randList : break;
			else :
				randList.append(N)
				N **= 2
				index = 0 if 8-len(str(N)) < 0 else 8-len(str(N)) 
				N = int((zero[:index] + str(N))[2:6])
		print len(randList)