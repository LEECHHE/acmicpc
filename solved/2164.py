cards = range(1,input()+1)
while len(cards) > 1 :
	if len(cards)%2 :
		cards = cards[len(cards)-1:] + cards[1::2]
	else :
		cards = cards[1::2]
print cards[0]