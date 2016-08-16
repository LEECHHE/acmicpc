p2 = [1]
for i in range(63):
	p2.append(p2[-1]*2);

def up(t):
	if t == '1':
		return '6'
	if t == '2':
		return '7'
	return t
def down(t):
	if t == '6':
		return '1'
	if t == '7':
		return '2'
	return t
p = list(raw_input())
k = input()
cnt = 0
code = []
for i in range(len(p)) :
	if p[i] == '1' or p[i] == '2' or p[i] == '6' or p[i] == '7':
		cnt += 1
		p[i] = down(p[i])
		code.append((p[i],i))

if k > p2[cnt] :
	print "-1"
else :
	c = bin(k-1)[2:]
	c = "0"*(cnt-len(c))+c
	for i in range(len(c)) :
		if c[i] == '1':
			p[code[i][1]] = up(code[i][0])
	print ''.join(p)