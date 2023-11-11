N = int(input())
answer = 0

if N % 7 == 0:
    answer |= 1

if "7" in str(N):
    answer |= 2

print(answer)
