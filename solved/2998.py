result = str(oct((int( raw_input() , 2 ))))
if result[len(result) - 1] == 'L' :
	print result[ 1 : len(result) - 1]
else :
	print result[ 1 : ]