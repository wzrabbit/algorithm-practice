N = int(input())
state = 0
is_success = True

for _ in range(N):
    message = input()
    if message == 'A':
        state += 1
    else:
        state -= 1
        if state < 0:
            is_success = False
            break

if is_success and state == 0:
    print('YES')
else:
    print('NO')