import math
n,k = [int(s) for s in raw_input().split()]
print(math.factorial(n)/math.factorial(k)/math.factorial(n-k))