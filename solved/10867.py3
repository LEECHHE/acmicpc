numbers = set()
N = input()
numbers = set([int(i) for i in input().split()])
for number in sorted(numbers):
    print (number, end=" ")