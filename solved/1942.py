def get_clk(s):
	return int(''.join([str(k).zfill(2) for k in s]))
for i in range(3):
	s1,s2 =[[int(k) for k in s.split(':')] for s in  raw_input().split()]
	ret = 0
	while True :
		if get_clk(s1) % 3 == 0 :
			ret += 1
			
		if  s1[0] == s2[0] and s1[1] == s2[1] and s1[2] == s2[2] :
			break

		s1[2] += 1
		if s1[2] >= 60 :
			s1[2] = 0
			s1[1] += 1
		if s1[1] >= 60 :
			s1[1] = 0
			s1[0] += 1
		if s1[0] >= 24 :
			s1[0] = 0
	print(ret)