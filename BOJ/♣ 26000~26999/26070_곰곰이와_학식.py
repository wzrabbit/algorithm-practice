def match():
    global A, B, C, X, Y, Z, cnt
    matched = min(A, X)
    A -= matched
    X -= matched
    cnt += matched

    matched = min(B, Y)
    B -= matched
    Y -= matched
    cnt += matched

    matched = min(C, Z)
    C -= matched
    Z -= matched
    cnt += matched

A, B, C = map(int, input().split())
X, Y, Z = map(int, input().split())
cnt = 0

for _ in range(3):
    match()
    X, Y, Z = Z // 3, X // 3, Y // 3
    
print(cnt)
     