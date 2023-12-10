N, K = map(int, input().split())
S = input()

right = S[: K - 1] if (N - K) % 2 == 1 else S[: K - 1][::-1]

print(S[K - 1 :] + right)
