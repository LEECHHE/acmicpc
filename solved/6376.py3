factorial = [1]*10
for i in range(1,10):
	factorial[i] = factorial[i-1]*i
def inv(n):
	return 1/n
print("n e\n- -----------")
e = list(map(inv,factorial))
for i in range(8) :
	print("%d %.10g" %(i,sum(e[:i+1])))
print("8 %.10g0" %(sum(e[:9])))
print("9 %.10g" %(sum(e)))