N, K = map(int, input().split())
MOD = 1000000007
mul = 1
answer = 0

def get_square_count(level):
    count = 2 * level - 1

    if level % 2 == 0:
        count -= 1

    count *= count

    if level % 2 == 0:
        count -= (level - 1) * (level - 2) * 2
    else:
        count -= level * (level - 1) * 2

    return count


for i in range(1, N + 1):
    mul = mul * K % MOD
    answer = (answer + (get_square_count(N - i + 1) * mul)) % MOD

print(answer)
