N = int(input())
pack_count = 0

if N == 4 or N == 7:
    print(-1)
    exit()

while True:
    if N % 5 == 0:
        pack_count += N // 5
        break

    N -= 3
    pack_count += 1

print(pack_count)
