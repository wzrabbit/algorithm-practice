before = input()
after = input()
before_count = before.count('1')
after_count = after.count('1')

if before_count % 2 == 0 and before_count < after_count:
    print('DEFEAT')
elif before_count + 1 < after_count:
    print('DEFEAT')
else:
    print('VICTORY')