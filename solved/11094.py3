for i in range(int(input())):
	s = input()
	idx = s.find("Simon says")
	if idx >= 0 :
		print(s[idx+10:])