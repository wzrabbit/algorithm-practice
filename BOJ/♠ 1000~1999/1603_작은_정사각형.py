def mex(numbers):
    cur = 0
    while True:
        if cur not in numbers:
            return cur
        cur += 1


def top_down(bit):
    if dp[bit] != -1:
        return dp[bit]

    grundy_numbers = set()

    for i in range(C * 2):
        if (bit & (1 << i)) == 0:
            new_bit = bit | (1 << i)
            grundy = top_down(new_bit)
            grundy_numbers.add(grundy)

    for i in range(C - 1):
        if (
            (bit & (1 << (C + i))) == 0
            and (bit & (1 << (C + i + 1))) == 0
            and (bit & (1 << i)) == 0
            and (bit & (1 << (i + 1))) == 0
        ):
            new_bit = (
                bit | (1 << (C + i)) | (1 << (C + i + 1)) | (1 << i) | (1 << (i + 1))
            )
            grundy = top_down(new_bit)
            grundy_numbers.add(grundy)

    dp[bit] = mex(grundy_numbers)
    return dp[bit]


for _ in range(3):
    R, C = map(int, input().split())
    game_result = 0

    while R > 0:
        grid = []
        dp = [-1] * (1 << (C * 2))

        for i in range(min(2, R)):
            grid.append(input())

        if R == 1:
            grid.append("#" * C)

        start_bit = 0
        level = 0
        for r in reversed(range(2)):
            for c in reversed(range(C)):
                if grid[r][c] == "#":
                    start_bit |= 1 << level
                level += 1

        game_result ^= top_down(start_bit)

        R -= 2

    print("M" if game_result == 0 else "Y")
