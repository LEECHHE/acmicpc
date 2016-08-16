for i in range(int(input())):
	n,s = [s for s in input().split()]
	n = int(n)
	print(''.join(list(map(lambda x: x*n, s))))