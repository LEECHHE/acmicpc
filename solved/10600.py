s = [['White', 255, 255, 255], ['Silver', 192, 192, 192], ['Gray', 128, 128, 128], ['Black', 0, 0, 0], ['Red', 255, 0, 0], ['Maroon', 128, 0, 0], ['Yellow', 255, 255, 0], ['Olive', 128, 128, 0], ['Lime', 0, 255, 0], ['Green', 0, 128, 0], ['Aqua', 0, 255, 255], ['Teal', 0, 128, 128], ['Blue', 0, 0, 255], ['Navy', 0, 0, 128], ['Fuchsia', 255, 0, 255], ['Purple', 128, 0, 128]]
def dist(a,b):
	return sum([(a1-b1)**2 for (a1,b1) in zip(a[1:],b)])
while True:
	color = [int(k) for k in raw_input().split()]
	if color[0] < 0 : break;
	ret = 'White'
	d = dist(s[0],color)
	for item in s :
		dd = dist(item,color)
		# print(dd)
		if d > dd :
			ret = item[0]
			d = dd
	print ret