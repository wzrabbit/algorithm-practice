T = int(input())

for _ in range(T):
    A, B, C = map(int, input().split())

    # assert: A, B, C 모두 0이 아니어야 한다.
    # 이 assert가 통과하지 못한다는 것은 데이터에 0이 존재한다는 뜻이다.
    # 무사히 통과하면, 해당 사항이 없다.
    assert(A != 0 and B != 0 and C != 0)

    candidates = [
        A + B,
        A - B,
        A * B,
        A / B,
        B - A,
        B / A
    ]

    if C in candidates:
        print('Possible')
    else:
        print('Impossible')
