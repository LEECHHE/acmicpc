factorial = [1]
for i in range(1,60):
	factorial.append(factorial[i-1]*i)
for i in range(int(raw_input())):
	t,n = [int(s) for s in raw_input().split(' ')]
	ret = 0
	b = int(int(n/2)/2)
	a = int(n/2)-2*b
	while b >= a :
		p = factorial[a+b]/factorial[a]/factorial[b]
		ret += p*p
		a += 2
		b -= 1
	print ("%d %d" %(t,ret))