import sys
input = sys.stdin.readline
books, limit = list(map(int, input().split(' ')))
book = list(map(int, input().split(' ')))
left = []
right = []
total = 0

for b in book:
    if b < 0:
        left.append(b)
    else:
        right.append(b)

left.sort()
right.sort(reverse=True)

leftIndex = 0
rightIndex = 0
if len(left) == 0:
    total += right[0]
    rightIndex += limit
elif len(right) == 0:
    total += left[0] * (-1)
    leftIndex += limit
elif abs(left[0]) > abs(right[0]):
    total += left[0] * (-1)
    leftIndex += limit
else:
    total += right[0]
    rightIndex += limit

while leftIndex < len(left):
    total += left[leftIndex] * (-2)
    leftIndex += limit

while rightIndex < len(right):
    total += right[rightIndex] * 2
    rightIndex += limit

print(total)
