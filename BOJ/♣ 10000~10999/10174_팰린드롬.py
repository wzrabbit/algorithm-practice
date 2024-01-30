T = int(input())

for _ in range(T):
    S = input().lower()

    if S == S[::-1]:
        print("Yes")
    else:
        print("No")
