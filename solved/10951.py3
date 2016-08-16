while True:
	S = input()
	if S =='':
		break;
	print(sum([int(s) for s in S.split()]))