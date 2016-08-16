n,m = [int(i) for i in input().split()]
mat = list()
for i in range(n):
	mat.append([int(k) for k in input().split()])
for i in range(n):
	add = [int(k) for k in input().split()]
	print(' '.join([str(x+y) for x,y in zip(mat[i],add)]))