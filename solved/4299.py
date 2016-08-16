scores = [int(a) for a in raw_input().split()]
result = [(scores[0] + scores[1]) * 0.5, (scores[0] - scores[1]) * 0.5]
if result[0] > int(result[0]) or result[1] > int(result[1]) or result[0] < 0 or result[1] < 0 :
	print -1
else :
	print "%d %d" %(int(result[0]), int(result[1]))