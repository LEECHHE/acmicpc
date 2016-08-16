import re
scores = []
for i in range(int(raw_input())):
	scores.extend([int(s) for s in re.findall(r'\d+', raw_input())])
for s in sorted(scores):
	print(s)