result = 0
max = result
for i in range(0, 4) :
	input = raw_input()
	sum = [int(s) for s in input.split()]
	result += sum[1] - sum[0]
	if max < result :
		max = result

print max