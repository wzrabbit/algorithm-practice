import math

N = int(input())
file_size = list(map(int, input().split()))
cluster_size = int(input())
total_size = 0

for i in range(N):
    total_size += cluster_size * math.ceil(file_size[i] / cluster_size)

print(total_size)
