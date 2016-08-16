N = input()
for i in range(N) :
	equation = raw_input().replace('@','*3').replace('%','+5').replace('#','-7').split()
	result = float(equation[0])
	for op in equation[1:] :
		result = eval(str(result) + op)
	print "%.2f" %result