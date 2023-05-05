N, H, V = map(int, input().split())
print(max(H, N - H) * max(V, N - V) * 4)
