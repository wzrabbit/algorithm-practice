N = int(input()) - 1
nums = [1]

while nums[-1] <= N:
    nums.append(nums[-1] * 2)

for i in range(len(nums)):
    if N - nums[i] in nums:
        print(nums[i] + 1)
        exit(0)

print("impossible")
