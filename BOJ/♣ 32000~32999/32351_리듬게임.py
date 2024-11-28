import sys
input = sys.stdin.readline

N, start_bpm, Q = input().split()
N = int(N)
start_bpm = float(start_bpm)
Q = int(Q)

prev_time = 1
prev_bpm = start_bpm
answer = 0.0

for i in range(Q):
    time, new_bpm = input().split()
    time = int(time)
    new_bpm = float(new_bpm)

    duration = time - prev_time
    answer += duration * (240 / prev_bpm)

    prev_time = time
    prev_bpm = new_bpm

duration = N - prev_time + 1
answer += duration * (240 / prev_bpm)

print(f'{answer:.12f}')
