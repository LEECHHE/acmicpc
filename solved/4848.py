numbers = [None]*16;
numbers[0] = '{}'
for i in range(1,16) :
	nextNum = ''
	for number in numbers :
		if number != None :
			nextNum += number + ','
	numbers[i] = '{'+nextNum[:len(nextNum)-1]+'}'
n = input()
for i in range(n) :
	print numbers[numbers.index(raw_input())+numbers.index(raw_input())]