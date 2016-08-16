n = int(input())
s = list()
dp = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
	s.append([int(k) for k in input().split()])
dp[0][0] = 1
for i in range(n):
	for j in range(n):
		if i == n-1 and j == n-1 : break;
		step = s[i][j]
		if step + i < n :
			dp[i+step][j] += dp[i][j]
		if step + j < n :
			dp[i][j+step] += dp[i][j]
print(dp[n-1][n-1])