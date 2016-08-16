N,M = [int(i) for i in input().split()]
not_heard = set()
not_see = set()
for i in range(N):
    not_heard.add(input())
for i in range(M):
    not_see.add(input())

not_heard_see = sorted(not_heard.intersection(not_see))
print (len(not_heard_see))
for name in not_heard_see:
    print (name)