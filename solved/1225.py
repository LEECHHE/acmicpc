num1 , num2 = [ int(s) for s in raw_input().split() ]
sum = 0;
while num2 > 0 :
	sum += num2 % 10
	num2 /= 10
result = 0
while num1 > 0 :
	result += sum * (num1 % 10)
	num1 /= 10
print result