three, four, both = map(int, input().split())

for i in range(0, both + 1):
    cur_three = three + i
    cur_four = four + (both - i)

    if cur_three % 3 == 0 and cur_four % 4 == 0:
        print(cur_three // 3, cur_four // 4)
        exit()

print(-1)
