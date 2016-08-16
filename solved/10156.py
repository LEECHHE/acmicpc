K,N,M = [int(s) for s in raw_input().split()]
if K * N > M :
	print K * N - M
else:
	print '0'