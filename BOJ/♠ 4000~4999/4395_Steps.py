def solve(dist):
    count = 0
    minus = 2

    while dist > 0:
        count += 1
        dist -= minus // 2
        minus += 1

    return count


t = int(input())
for _ in range(t):
    start, end = map(int, input().split())
    print(solve(end - start))
