import string
for i in range(int(input())):
	encrypted = raw_input()
	rules = {}
	keys = raw_input()
	for c in string.ascii_uppercase:
		rules[c] = keys[ord(c)-ord('A')];
	rules[" "] = " ";
	ret = []
	for e in encrypted:
		ret.append(rules[e])
	print ''.join(ret)