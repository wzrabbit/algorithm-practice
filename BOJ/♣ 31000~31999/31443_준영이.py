R, C = map(int, input().split())
area = R * C
happiness = 1
MOD = 1_000_000_007

while area >= 2:
    if area == 2 or area == 4:
        happiness = happiness * 2 % MOD
        area -= 2
    else:
        happiness = happiness * 3 % MOD
        area -= 3

print(happiness)
