dp = {}
dp[0] = 1; dp[1] = 1
while True :
	N = input()
	for i in range( 2, N+1 ) :
		dp[i] = dp[i-1] + dp[i-2] * 2
	print dp[N]