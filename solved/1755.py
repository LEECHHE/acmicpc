numbers = {
	1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine', 0:'zero'
}
M, N = [int(s) for s in raw_input().split()]
result = {}
for n in range(M, N+1) :
	numberString = numbers[n%10]
	if n >= 10 :
		numberString = numbers[n/10] + " " + numberString
	result[numberString] = n
count = 0
for n in sorted(result.items(), key=lambda x:x[0]) :
	if count < 9:
		count += 1;	print n[1],
	else :
		count = 0; print n[1]