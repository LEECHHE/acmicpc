from collections import defaultdict
import operator
N = input()
books = defaultdict(lambda: 0, dict())
for i in range(0,N) :
	books[raw_input()] += 1
maxValue = max(books.iteritems(), key=operator.itemgetter(1))[1]
maxBooks = filter(lambda name: books[name] == maxValue, dict(books.iteritems()))
print sorted(maxBooks)[0]