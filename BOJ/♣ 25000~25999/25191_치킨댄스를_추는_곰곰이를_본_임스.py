chicken = int(input())
coke, beer = map(int, input().split())

print(min(coke + beer * 2, chicken * 2) // 2)
