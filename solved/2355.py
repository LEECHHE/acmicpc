i_j = [ int(s) for s in raw_input().split()]
def swap( i, j ):
	return j, i
if i_j[0] > i_j[1] :
	i_j[0], i_j[1] = swap( i_j[0] , i_j[1] )
if i_j[1] < 0 and i_j[0] < 0 :
	print  (-1) * (i_j[0] * (i_j[0] - 1) / 2 - (i_j[1] + 1) * (i_j[1]) / 2)
elif i_j[0] <= 0 and i_j[1] >= 0 :
	print i_j[1] * (i_j[1] + 1) / 2 - i_j[0] * (i_j[0] - 1) / 2 
else :
	print i_j[1] * (i_j[1] + 1) / 2 - (i_j[0]-1) * i_j[0] / 2