document = input()
word = input()
ret = 0
idx = 0
length = len(word)
while True:
	idx = document.find(word, idx)
	if idx < 0 :
		break
	ret += 1
	idx += length
print(ret)