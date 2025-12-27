start_h, start_m, start_s = map(int, input().split(':'))
end_h, end_m, end_s = map(int, input().split(':'))
time, rate = map(int, input().split())

left_time = (end_h - start_h) * 3600 + (end_m - start_m) * 60 + end_s - start_s

if time // 100 * (100 - rate) <= left_time:
    print(1)
else:
    print(0)
