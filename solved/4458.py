N = input()
for i in range(N):
	string = raw_input()
	if ord(string[0]) >= ord('a') :
		print chr(ord(string[0]) - ord('a') + ord('A')) + string[1:];
	else :
		print string