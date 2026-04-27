A, B = map(int, input().split())
answer = A
cur = A

while cur >= B:
    answer += cur // B
    cur //= B

print(answer)
