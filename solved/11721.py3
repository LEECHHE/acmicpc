s = input()
idx = 0
while(1):
	limit = idx+10
	if limit > len(s) :
		print (s[idx:])
		break
	print (s[idx:limit])
	idx += 10