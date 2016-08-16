N = input()
for i in range(N) :
	r,e,c = [int(k) for k in raw_input().split()]
	if r < e-c : print "advertise";
	elif r == e-c : print "does not matter";
	else : print "do not advertise";