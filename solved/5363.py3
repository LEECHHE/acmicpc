for i in range(int(input())):
	s = input().split()
	print(' '.join([' '.join(s[2:]), ' '.join(s[:2])]))