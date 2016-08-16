import math
values = {'A+':4.3, 'A0': 4.0, 'A-': 3.7, 
'B+': 3.3, 'B0': 3.0, 'B-': 2.7,
'C+': 2.3, 'C0': 2.0, 'C-': 1.7,
'D+': 1.3, 'D0': 1.0, 'D-': 0.7, 'F': 0.0}
n = input()
credit = 0
total = 0
for i in range(n):
	score = raw_input().split()[1:]
	credit += int(score[0])
	total += int(score[0]) * values[score[1]]
print '%.2f' %(math.floor((total/credit*100+0.5))/100)