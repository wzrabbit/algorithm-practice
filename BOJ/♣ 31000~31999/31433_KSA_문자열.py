def get_answer(start_index):
    ksa_count = 0
    cur_index = start_index
    max_ksa_limit = len(X) - start_index

    for i in range(len(X)):
        if X[i] == KSA[cur_index]:
            ksa_count += 1
            cur_index = (cur_index + 1) % 3

    ksa_count = min(ksa_count, max_ksa_limit)

    return (len(X) - ksa_count) * 2


X = input()
KSA = "KSA"

assert len(X) >= 1 and len(X) <= 500_000
assert X.count("K") + X.count("S") + X.count("A") == len(X)

answer = min(get_answer(0), get_answer(1), get_answer(2))

print(answer)
