while True:
	seq = input()
	if seq == '':
		break
	ret = [0]*4
	for s in seq :
		if ord('0') <= ord(s) and ord(s) <= ord('9'):
			ret[2] += 1
		elif s == ' ':
			ret[3] += 1
		elif s.lower() == s :
			ret[0] += 1
		else:
			ret[1] += 1
	print(' '.join(map(str,ret)))