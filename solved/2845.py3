real = [int(i) for i in input().split()]
real = real[0]*real[1]
for i in input().split():
	print(int(i)-real,end=" ")