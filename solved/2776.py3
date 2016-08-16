for i in range(int(input())):
	d = dict()
	input()
	seq = [int(k) for k in input().split()]
	for n in seq:
		d[n] = True
	input()
	for n in [int(p) for p in input().split()]:
		if n in d:
			print ("1")
		else:
			print("0")