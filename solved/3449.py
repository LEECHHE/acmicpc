T = input()
for i in range(0, T+1) :
	count = 0
	a = int(raw_input(),2) ^ int(raw_input(),2)
	for binary in bin(a) :
		if binary == '1' :
			count += 1
	print 'Hamming distance is %d.' %count