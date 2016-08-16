while True :
	s = input()
	if s == '0' : break;
	while len(s) > 1 :
		s = str(sum([int(k) for k in s]))
	print(s)