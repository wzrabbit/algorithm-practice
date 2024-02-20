N, K, P = map(int, input().split())
breads = list(map(int, input().split()))

no_cream_count = 0
bundle_count = 0

for i in range(N * K):
    if breads[i] == 0:
        no_cream_count += 1

    if i % K == K - 1:
        if no_cream_count < P:
            bundle_count += 1

        no_cream_count = 0

print(bundle_count)
