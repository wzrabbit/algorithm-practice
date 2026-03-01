def get_weight(num):
    return len(str(num)) * sum(map(int, str(num)))

A, B = map(int, input().split())

A_weight = get_weight(A)
B_weight = get_weight(B)

if A_weight > B_weight:
    print(1)
elif A_weight < B_weight:
    print(2)
else:
    print(0)
