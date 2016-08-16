from collections import defaultdict
N = input()
for i in range(N) :
	s1, s2 = raw_input().split()
	dict_s1 = defaultdict(lambda: 0, dict())
	dict_s2 = defaultdict(lambda: 0, dict())
	for ch1 in s1 : dict_s1[ch1] += 1
	for ch2 in s2 : dict_s2[ch2] += 1
	if dict_s1 == dict_s2 :
		print '%s & %s are anagrams.' %(s1, s2) 
	else :
		print '%s & %s are NOT anagrams.' %(s1, s2)