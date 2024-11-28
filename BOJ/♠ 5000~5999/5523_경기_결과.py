import sys
input = sys.stdin.readline

N = int(input())
a_score = 0
b_score = 0

for _ in range(N):
    a, b = map(int, input().split())

    if a > b:
        a_score += 1
    
    if a < b:
        b_score += 1

print(a_score, b_score)
