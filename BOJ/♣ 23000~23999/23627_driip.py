import re
a = input().strip()
x = re.search('driip$', a)

if x:
    print('cute')
else:
    print('not cute')
