import sys
input = sys.stdin.readline


def time_to_num(time):
    h, m = map(int, time.split(':'))
    return h * 60 + m


def num_to_time(num):
    h = str(num // 60).zfill(2)
    m = str(num % 60).zfill(2)

    return f'{h}:{m}'


current = time_to_num(input())
N = int(input())
success = True

for _ in range(N):
    data = input().split()
    start = time_to_num(data[0])
    end = time_to_num(data[1])
    time = int(data[2])

    current = max(current, start)
    if current + time <= end:
        current += time
    else:
        success = False
        break

if success:
    print(f'Yes\n{num_to_time(current)}')
else:
    print('No')
