import sys
input = sys.stdin.readline

N = int(input())
palindrome_count = 0

for _ in range(N):
    S = input().strip()

    if S == S[::-1]:
        palindrome_count += 1

print(palindrome_count * (palindrome_count - 1))
