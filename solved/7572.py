gan= range(0,10)
easy = 'ABCDEFGHIJKL'
N = input()
print easy[(N+8)% 12]+str(gan[(N+6)% 10])