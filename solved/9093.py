for i in range(input()):
	sentence = raw_input().split()
	print " ".join([word[::-1] for word in sentence])