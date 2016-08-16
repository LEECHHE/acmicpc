N = input()
for i in range(N) :
	num = bin(input())
	pos = 0
	for i in num[::-1] :
		if(i == '1') : print "%d" % pos,
		pos += 1
	print ""