for i in range(int(input())):
    print("Scenario #%d:" %(i+1))
    l = sorted([int(s) for s in input().split()])
    if l[2]**2 == l[0]**2 +l[1]**2 :
        print("yes")
    else:
        print("no")
    print()