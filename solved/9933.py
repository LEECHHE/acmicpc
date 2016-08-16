N = input()
words = []
for i in range(N):
	temp = raw_input()
	words.append(temp)
	if temp[::-1] in words :
		print '%d %s' %(len(temp), temp[len(temp)/2])
		break;