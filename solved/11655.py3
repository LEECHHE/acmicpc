def rot(s):
	if s < 'A' or s == ' ' or s == '\n' : 
		return s
	s = ord(s)+13
	if s > ord('z'):
		return chr(s+ord('a')-ord('z')-1)
	elif ord('Z') < s and s <= ord('Z')+13 :
		return chr(s+ord('A')-ord('Z')-1)
	else:
		return chr(s)

s = input()
ret = ""
for i in range(len(s)):
	ret += rot(s[i])
print(ret)