for i in range(int(raw_input())):
	t,n = [int(s) for s in raw_input().split(' ')]
	print(' '.join([str(t),str(n*(n+1)/2), str(n*n), str(n*n+n)]))