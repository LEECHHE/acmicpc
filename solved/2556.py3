n = int(input())
if n == 1 :
	print ('*')
else :
	print('*'*n)
	line = '*'+'*'*(n-2) +'*'
	for i in range(n-2):
		print(line)
	print('*'*n)