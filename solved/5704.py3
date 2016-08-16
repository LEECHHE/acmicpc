while True :
	sentence = input()
	alphabets = [False]*26
	if sentence == '*':
		break;
	else :
		for i in range(len(sentence)):
			if(sentence[i] == ' '):
				continue
			alphabets[ord(sentence[i])-ord('a')] = True
		if all(alphabets) : 
			print("Y")
		else:
			print("N")