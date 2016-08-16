import sys
N = raw_input()
arr = [int(N[i]) for i in range( 0, len(N) )]
arr.sort(reverse = True)
for i in range( 0, len(N) ) :
	sys.stdout.write(str(arr[i]))