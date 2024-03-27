def get_range_sum(a, d, n):
    return n * (2 * a + (n - 1) * d) // 2


def get_toka_position(time):
    moved = get_range_sum(B, -K, min(time, toka_run_limit))
    return A - moved


def get_doldol_position(time):
    return A + C - D * time


def get_toka_run_limit():
    if K == 0:
        return 10**19

    return (B - B % K) // K + 1


A, B = map(int, input().split())
C, D = map(int, input().split())
K = int(input())
toka_run_limit = get_toka_run_limit()

start = 1
end = 10**18
mid = None

while start <= end:
    mid = (start + end) // 2

    toka_position = get_toka_position(mid)
    doldol_position = get_doldol_position(mid)

    if toka_position > 0 and doldol_position <= 0:
        print(-1)
        exit()

    if toka_position <= 0:
        end = mid - 1
    else:
        start = mid + 1

final_doldol_position = get_doldol_position(start)

if final_doldol_position <= 0:
    print(-1)
else:
    print(start)
