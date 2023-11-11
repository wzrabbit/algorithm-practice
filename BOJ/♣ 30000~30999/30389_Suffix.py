N = int(input())
suffix_set = set()

for _ in range(N):
    S = input()
    for i in range(len(S)):
        cur_suffix = S[i:]

        if cur_suffix in suffix_set:
            suffix_set.remove(cur_suffix)
        else:
            suffix_set.add(cur_suffix)

print(len(suffix_set))
