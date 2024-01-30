_, month, day = map(int, input().split('-'))

if month >= 10:
    print('TOO LATE')
    exit()
    
if month == 9 and day > 16:
    print('TOO LATE')
    exit()
    
print('GOOD')