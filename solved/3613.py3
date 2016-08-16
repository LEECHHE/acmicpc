s = input()
cap = [chr(ord('A')+i) for i in range(26)]
low = [chr(ord('a')+i) for i in range(26)]
def toCpp(seq):
	for i in range(26):
		seq = seq.replace(cap[i],'_'+low[i])
	return seq

def toJava(seq):
	for i in range(26):
		seq = seq.replace('_'+low[i],cap[i])
	return seq

kind = 0
for i in range(len(s)):
	if ord('A') <= ord(s[i]) and ord(s[i]) <= ord('Z') :
		if kind == 0 :
			kind = 1		# JAVA
		elif kind != 1 :
			kind = 3
		if i == 0 :
			kind = 3	#Error
			break
	elif s[i] == '_':
		if i == 0 or i == len(s)-1 or not (ord('a') <= ord(s[i+1]) and ord(s[i+1]) <= ord('z')) :
			kind = 3
			break

		if kind == 0 :
			kind = 2
		elif kind != 2 :
			kind = 3
			break
if kind <= 1:
	print(toCpp(s))
elif kind == 2 :
	print(toJava(s))
else:
	print("Error!")