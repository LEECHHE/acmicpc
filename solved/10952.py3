while True:
	S = input()
	if S =="0 0":
		break;
	print(sum([int(s) for s in S.split()]))