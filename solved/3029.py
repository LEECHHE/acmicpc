start = [int(t) for t in raw_input().split(':')]
end = [int(t) for t in raw_input().split(':')]
result = [ end[i] - start[i] for i in range(3)]
if result[2] < 0 :
	result[2]= result[2]+60
	result[1] -= 1
if result[1] < 0 :
	result[1] = result[1]+60
	result[0] -= 1
if result[0] < 0 :
	result[0] = result[0]+24

if result[0] == 0 and result[1] == 0 and result[2] == 0 :
	result[0] = 24
print "%02d:%02d:%02d" %(result[0], result[1], result[2])