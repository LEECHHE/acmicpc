while(True):
	words = raw_input().lower()
	if words == '*' : 
		break;
	else :
		tauto = words.split()
		isTautogram = 'Y'
		initial = tauto[0][0]
		for word in tauto :
			if word[0] != initial :
				isTautogram = 'N'
				break
		print isTautogram