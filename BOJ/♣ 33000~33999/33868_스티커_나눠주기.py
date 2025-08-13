N = int(input())
longest_time = 0
shortest_code = 999999

for _ in range(N):
    T, B = map(int, input().split())
    longest_time = max(longest_time, T)
    shortest_code = min(shortest_code, B)

print(longest_time * shortest_code % 7 + 1)
