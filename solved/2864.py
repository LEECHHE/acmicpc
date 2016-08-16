A, B = raw_input().split()
a = A.replace('6','5')
b = B.replace('6','5')
print int(a) + int(b),
a = A.replace('5','6')
b = B.replace('5','6')
print int(a) + int(b)