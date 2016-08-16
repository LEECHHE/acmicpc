import calendar
m,n = input().split()
week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
print(week[calendar.weekday(2009, int(n),int(m))])