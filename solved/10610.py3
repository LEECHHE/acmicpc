seq = input()
hasZero = False
sum3 = sum([int(i) for i in seq])
for i in seq:
	if i == '0' :
		hasZero = True
		break;
if hasZero and sum3%3 == 0 :
	print(''.join(sorted(seq, reverse = True)))
else:
	print("-1")