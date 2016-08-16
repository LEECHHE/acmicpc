s = bin(int(input()))
ret = 0
pow3 = 1
for i in range(len(s)-1,1,-1):
	if s[i] == '1':
		ret += pow3
	pow3 *= 3
print (ret)