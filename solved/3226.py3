total = 0
fare = {0:10, 1:5}
#state = 0
def state(hour):
	if (hour >= 0 and hour <= 11):
		return 0
	else:
		return 1
for i in range(int(input())):
	time, duration = [s for s in input().split()]
	h, m = [int(s) for s in time.split(':')]
	duration = int(duration)
	#다 7시간씩 빼서 계산
	h -= 7
	if h < 0 : h += 24;
	
	# setState(h,m)
	for i in range(duration):
		m += 1
		total += fare[state(h)]
		# print("fare for %d:%d is %d" %(h,m,fare[state(h)]))
		if m >= 60 :
			h += 1
			m = 0
			if h >= 24 :
				h = 0
			# setState(h,m)
print (total)