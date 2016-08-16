from math import ceil
def fold(seq):
	for i in range(ceil(len(seq)/2)):
		seq[i] += seq[-i-1]
	return seq[:ceil(len(seq)/2)]
for t in range(int(input())):
	print("Case #%d: " %(t+1),end="")
	input()
	seq = [int(i) for i in input().split()]
	while len(seq) > 2:
		seq = fold(seq)
	if seq[0] > seq[1]:
		print("Alice")
	else:
		print("Bob")