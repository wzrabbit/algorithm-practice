h, m = map(int, input().split())
add = int(input())

total = (h * 60 + m + add) % 1440
print(total // 60, total % 60)
