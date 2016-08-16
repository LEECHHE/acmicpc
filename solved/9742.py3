import itertools
factorial = [1]
for i in range(1,11):
	factorial.append(i * factorial[i-1])
while True:
	word= input()
	if word == '' :
		break
	word,n = word.split()
	n = int(n)
	
	print("%s %d = " %(word, n), end="")
	if factorial[len(word)] < n :
		print("No permutation")
		continue
	print(''.join(sorted(list(itertools.permutations(word)))[n-1]))