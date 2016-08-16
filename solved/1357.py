x,y = raw_input().split()
print int(str(int(x[::-1]) + int(y[::-1]))[::-1])