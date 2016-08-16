factorial = [1]*13
for i in range(1,13):
	factorial[i] = factorial[i-1]*i
print(factorial[int(input())])