a,b = raw_input().split()
if len(a) > len(b):
	b = b.zfill(len(a))
else:
	a = a.zfill(len(b))

print ''.join([str(int(p)+int(q)) for p,q in zip(a,b)])
