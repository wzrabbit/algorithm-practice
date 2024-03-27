N, S = input().split()
N = int(N)
total_count = 0

for i in range(N):
    frags, count = input().split()
    count = int(count)
    frags = frags.split("_")

    if S in frags:
        total_count += count

print(total_count)
