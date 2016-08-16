#1551
n,k = [int(i) for i in input().split()]
numbers = [int(i) for i in input().split(',')]
for cnt in range(k):
	for i in range(len(numbers)-1):
		numbers[i] = numbers[i+1] - numbers[i]
	numbers.pop()
	# print(numbers)

print(",".join([str(element) for element in numbers]))