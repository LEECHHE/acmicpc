sub = { 'AA':'A', 'AG':'C', 'AC':'A', 'AT':'G', \
		'GA':'C', 'GG':'G', 'GC':'T', 'GT':'A', \
		'CA':'A', 'CG':'T', 'CC':'C', 'CT':'G', \
		'TA':'G', 'TG':'A', 'TC':'G', 'TT':'T'}
N = input()
dna = raw_input()
for i in range(N,1,-1):
	dna = dna[:i-2]+sub[dna[i-2:]]
print dna