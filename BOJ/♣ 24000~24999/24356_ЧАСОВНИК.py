t1, m1, t2, m2 = map(int, input().split())

start_minutes = t1 * 60 + m1
end_minutes = t2 * 60 + m2

duration = end_minutes - start_minutes

if duration < 0:
    duration += 1440

laps = duration // 30

print(duration, laps)
