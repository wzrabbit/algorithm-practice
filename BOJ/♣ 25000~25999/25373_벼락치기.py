N = int(input())

if N == 1:
    print(1)
elif 2 <= N <= 3:
    print(2)
elif 4 <= N <= 6:
    print(3)
elif 7 <= N <= 10:
    print(4)
elif 11 <= N <= 15:
    print(5)
elif 16 <= N <= 21:
    print(6)
else:
    answer = N // 7
    if answer % 7 != 0:
        answer += 1
    print(answer + 3)
