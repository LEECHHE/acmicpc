pos = []
cur = 0
s = input()
for i in range(len(s)):
	if s[i] == '(':
		pos.append(cur-1)
		pos.append(s[i-1])
		cur = 0
	elif s[i] == ')':
		Q = cur
		K = pos.pop()
		cur = int(K)*Q+pos.pop();
	else:
		cur += 1
print (cur)