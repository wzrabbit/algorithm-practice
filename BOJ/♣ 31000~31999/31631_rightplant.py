import sys

print = sys.stdout.write

N = int(input())

left = [N - 1]
right = [N]
left_sum = N - 1
right_sum = N

for i in reversed(range(1, N - 1)):
    if left_sum + 1 <= right_sum:
        left_sum += i
        left.append(i)
    else:
        right_sum += i
        right.append(i)

for i in left:
    print(f"{i} ")

for i in reversed(right):
    print(f"{i} ")
