menu = []
used = [False]*26
for i in range(int(input())):
	menu.append(input().split())
defined = [False]*len(menu)
for i in range(len(menu)) :
	for k,word in enumerate(menu[i]) :
		if not used[ord(word[0].upper())-ord('A')]:
			used[ord(word[0].upper())-ord('A')] = True
			defined[i] = True
			menu[i][k] = '['+word[0]+']'+word[1:]	
			break
	if not defined[i] :
		for k,word in enumerate(menu[i]) :
			for j in range(len(word)):
				if not used[ord(word[j].lower())-ord('a')]:
					used[ord(word[j].lower())-ord('a')] = True
					defined[i] = True
					menu[i][k]= word[:j]+'['+word[j]+']'+word[j+1:]	
					break
			if defined[i] :
				break

for m in menu :
	print(' '.join(m))