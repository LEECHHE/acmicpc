while(True) :
	words = raw_input()
	while 'BUG' in words :
		words = words.replace('BUG','')
	print words