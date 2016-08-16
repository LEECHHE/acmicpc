n,m = raw_input().split()
s = ''.join([n]*int(n))
if len(s) > int(m) :
    s = s[:int(m)]
print (s)