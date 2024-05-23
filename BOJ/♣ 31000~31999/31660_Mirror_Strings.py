def get_mul_sum(x, y):
    total = 0
    mul = x

    for i in range(1, y + 1):
        total = (total + mul) % MOD

        if i % 2 == 0:
            mul = mul * x % MOD

    return total


L, R = map(int, input().split())
MOD = 10**9 + 7

print(
    (
        (
            get_mul_sum(2, R)
            - get_mul_sum(2, L - 1)
            + get_mul_sum(5, R)
            - get_mul_sum(5, L - 1)
        )
        + (MOD * 4)
    )
    % MOD
)
