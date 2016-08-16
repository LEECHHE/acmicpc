case = 1
while True:
	s = input()
	if s.split()[1] == 'E' :
		break
	print("Case %d: %s" %(case,str(eval(s)).lower()))
	case += 1