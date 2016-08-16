N = int(input())
current, standard = input().split()
standard = float(standard[3:])

def toTime(difference):
    time = difference.split('.')
    hour = int(time[0])
    min = 0
    if time[1] == '5' :
        min = 30
    if difference[0] == '-':
        min *= -1
    return hour, min

def GetUTC(current, difference):
    diff_hour, diff_min = toTime(difference)
    current_hour, current_min = [int(t) for t in current.split(":")]
    
    current_min += diff_min
    if current_min >= 60 :
        current_min -= 60
        current_hour += 1
    elif current_min < 0 :
        current_min += 60
        current_hour -= 1

    current_hour += diff_hour
    if current_hour >= 24 :
        current_hour -= 24
    elif current_hour < 0:
        current_hour += 24

    print ('%02d:%02d' %(current_hour, current_min)) 

for i in range(N):
    remote_standard = float(input()[3:])

    difference = str(remote_standard - standard)
    GetUTC(current, difference)