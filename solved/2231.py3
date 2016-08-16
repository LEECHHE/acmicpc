def decompose(n):
	if n <= 0 : return 0;
	return n+sum([int(s) for s in str(n)])
n = int(input())
ret = 0
for i in range(n-len(str(n))*9,n):
	if decompose(i) == n :
		ret = i
		break
print(ret)