N = input()
count = 0
for one in bin(N)[2:] :
	if one == '1' : count += 1
print count