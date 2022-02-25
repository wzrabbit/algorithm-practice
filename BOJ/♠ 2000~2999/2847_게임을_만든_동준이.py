import sys
cases = int(sys.stdin.readline())
nums = []
total = 0

for i in range(cases):
    nums.append(int(sys.stdin.readline()))
nums.reverse()

for i in range(cases - 1):
    if nums[i] <= nums[i + 1]:
        total += nums[i + 1] - nums[i] + 1
        nums[i + 1] = nums[i] - 1

print(total)
