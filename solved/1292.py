i = 0
k = 1
arr = { }
while i < 1000:
	for j in range( 0, k ) :
		arr[i] = k
		i += 1
	k += 1

k = 0;
input = raw_input()
limit = [int(s) for s in input.split()]
for i in range( limit[0]-1, limit[1] ):
	k += arr[i];

print k