cur_max = -1;
index = -1;
for i in range( 0, 9 ) :
	cur = max( input(), cur_max )
	if cur_max <  cur :
		cur_max = cur
		index = i + 1

print cur_max
print index