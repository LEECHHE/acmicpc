for i in range(int(input())):
	included = [False]*26
	for s in input().lower():
		s = ord(s)
		if ord('a') <= s and s <= ord('z') :
			included[s-ord('a')] = True
	res = ''.join(map(lambda x :chr(x+ord('a')) ,filter(lambda x : not included[x], range(26))))
	if res == '':
		print("pangram")
	else:
		print ("missing "+res)