def getScore(scores) :
	if scores[3]-scores[1] >= 4 :
		return "KIN"
	else :
		return sum(scores[1:4])
		
N = input()
for i in range(N) :
	scores = sorted([ int(s) for s in raw_input().split()])
	print getScore(scores)