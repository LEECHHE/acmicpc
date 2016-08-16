limit = 2 ** int(raw_input())
result = str(bin(( limit - 1 ) * limit / 2))
print result[2:]