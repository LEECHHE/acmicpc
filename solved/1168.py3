n,m = [int(s) for s in input().split()]
seq = [i+1 for i in range(n)]
ans = []
removed = m-1
while True :
	ans.append(str(seq[removed]))
	seq.pop(removed)
	if len(seq) == 0 : break;
	removed += m-1
	removed %= len(seq)
print("<"+', '.join(ans)+">")