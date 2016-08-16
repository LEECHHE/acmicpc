p2 = [1]
for i in range(7):
	p2.append(p2[-1]*256)
p2 = p2[::-1]
for i in range(input()):
	t,a = raw_input().split()
	if t == '1':
		print(sum([p*q for p,q in zip(p2,[int(s) for s in a.split('.')])]))
	else:
		a = int(a)
		ip = [0]*8
		for i in range(8):
			ip[i] = int(a/p2[i])
			a %= p2[i]
		print('.'.join(map(lambda x:str(x),ip)))