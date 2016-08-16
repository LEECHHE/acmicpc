T = input()
for i in range(0,T):
	k = input(); n = input();
	number_of_people = [ num for num in range(1,n+1)]
	for j in range(0,k) :
		for l in range(1,n) :
			number_of_people[l] += number_of_people[l-1]
	print number_of_people[n-1]