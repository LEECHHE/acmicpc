conditions = {
	1 : [[],[0,0,0]],
	2 : [[0]],
	3 : [[0,1],[-1]],
	4 : [[-1,0], [1]],
	5 : [[0,0], [-1],[1],[-1,1]],
	6 : [[0,0],[-2],[0],[1,0]],
	7 : [[0,0],[2],[0],[0,-1]]
}
n, p = [int(s) for s in input().split()]
lines = [ int(s) for s in input().split()]
ret = 0
# print("block %d is used" %(p))
for cond in conditions[p]:
	if len(cond) == 0 :
		ret += len(lines)
		continue
	# for series in cond:
	for idx in range(len(lines)-len(cond)):
		satisfy = True
		for s in range(1,len(cond)+1):
			if lines[idx+s] != lines[idx+s-1] + cond[s-1]:
				satisfy = False
				break
		if satisfy : 
			#print("Satisfy on idx %d with condition " %(idx), end="")
			#print(cond)
			ret += 1
print(ret)