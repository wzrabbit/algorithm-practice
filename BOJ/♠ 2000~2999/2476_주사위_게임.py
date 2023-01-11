N = int(input())
max_price = 0

for _ in range(N):
    nums = sorted(list(map(int, input().split())))
    current_price = 0

    if nums[0] == nums[2]:
        current_price = 10000 + nums[0] * 1000
    elif nums[0] == nums[1] or nums[1] == nums[2]:
        current_price = 1000 + nums[1] * 100
    else:
        current_price = nums[2] * 100

    max_price = max(max_price, current_price)

print(max_price)
