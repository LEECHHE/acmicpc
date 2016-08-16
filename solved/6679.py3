def base(n,k):
	ret = 0
	while k > 0 :
		ret += k%n
		k = (int(k/n))
	return ret

for i in range(1000,10000):
	b10 = sum([int(s) for s in str(i)])
	b12 = base(12,i)
	b16 = base(16,i)
	if b12 == b16 and b10 == b12 :
		print(i)