q = []
for i in range(input()):
	s = raw_input().split()
	op = s[0]
	n = 0
	if len(s) > 1 :
		n = int(s[1])
	if op == "push":
		q.append(n)
	elif op == "pop":
		if len(q) == 0 :
			print -1
		else :
			print q.pop(0)
	elif op == "size":
		print len(q)
	elif op == "empty":
		if len(q) == 0 :
			print 1
		else:
			print 0
	elif op == "front":
		if len(q) == 0 :
			print -1
		else:
			print q[0]
	else :
		if len(q) == 0:
			print -1
		else :
			print q[-1]