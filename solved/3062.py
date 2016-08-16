N = input()
for i in range(N) :
	number = raw_input()
	number = str(int(number)+int(number[::-1]))
	success = True
	for j in range(len(number)/2) :
		if number[j] != number[len(number)-j-1] :
			success = False
			break
	if success : print "YES";
	else : print "NO";