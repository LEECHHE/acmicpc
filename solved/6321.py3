for i in range(int(input())):
	print("String #"+str(i+1))
	print(''.join([chr((ord(c)+1)) for c in input()]).replace('[','A')+'\n')