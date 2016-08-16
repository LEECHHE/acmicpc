e,s,m = [int(i) for i in input().split()]
a,b,c = [1,1,1]
ret = 1
while not(a == e and b == s and c == m) :
	c += 1
	b += 1
	a += 1
	if c == 20 :
		c = 1
	if b == 29 :
		b = 1
	if a == 16:
		a = 1
	ret += 1
print(ret)