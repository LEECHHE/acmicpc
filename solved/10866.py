q = []
for i in range(input()):
	s = raw_input().split()
	op = s[0]
	n = 0
	if len(s) > 1 :
		n = int(s[1])
	if op == "push_back":
		q.append(n)
	elif op == "push_front":
		q.insert(0,n)
	elif op == "pop_front":
		if len(q) == 0 :
			print -1
		else :
			print q.pop(0)
	elif op == "pop_back":
		if len(q) == 0 :
			print -1
		else :
			print q.pop()
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