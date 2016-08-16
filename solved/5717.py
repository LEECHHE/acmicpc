while True:
	f = [ int(i) for i in raw_input().split()]
	if f[0] is 0 and f[1] is 0 : break;
	print sum(f)