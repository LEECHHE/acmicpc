#1408
before =[ int(s) for s in input().split(':')]
after = [ int(s) for s in input().split(':')]
#second
if before[2] > after[2]:
	after[2] += 60
	after[1] -= 1
#minute
if before[1] > after[1]:
	after[1] += 60
	after[0] -= 1
#hour
if before[0] > after[0]:
	after[0] += 24

result = [a-b for (b,a) in zip(before, after)]
if result[0] >= 24:
	result[0] -= 24
print("%02d:%02d:%02d" %(result[0], result[1], result[2]))