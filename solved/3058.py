N = input()
for i in range(N) :
	numbers = [int(n) for n in raw_input().split()]
	numbers = sorted(filter(lambda x: x % 2 == 0, numbers))
	print sum(numbers), numbers[0]