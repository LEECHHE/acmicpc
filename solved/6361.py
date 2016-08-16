def dec(a):
	a = ord(a)
	if ord('0') <= a and a <= ord('9') :
		return a-ord('0')
	if ord('A')<= a and a <= ord('Z'):
		return a-ord('A')+10
	if ord('a')<= a and a <= ord('z'):
		return a-ord('a')+36
def number(a):
	if 0 <= a and a <= 9 :
		return str(a)
	if 10 <= a and a <= 35:
		return chr(a-10+ord('A'))
	return chr(a-36+ord('a'))
for i in range(int(raw_input())):
	x,y,seq = raw_input().split()
	print x+" "+seq
	if seq == '0':
		print y+" 0\n"
		continue
	x = int(x)
	y = int(y)
	p = 1
	before = 0
	for j in range(len(seq)-1,-1,-1):
		before += p*dec(seq[j])
		p *= x
	converted = []
	while before > 0:
		converted.append(number(before%y))
		before = int(before/y)
	if converted[-1] == '0' :
		converted = converted[:len(converted)-1]
	
	print str(y)+" "+''.join(converted[::-1])+"\n"