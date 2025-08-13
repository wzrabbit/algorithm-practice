def get_lis(arr):
    lis = [1] * N

    for i in range(1, N):
        for j in range(i):
            if arr[j] < arr[i] and lis[j] + 1 > lis[i]:
                lis[i] = lis[j] + 1

    return max(lis)

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A_score = 0
B_score = 0

for _ in range(N):
    A_score = max(A_score, get_lis(A))
    A.append(A.pop(0))

    B_score = max(B_score, get_lis(B))
    B.append(B.pop(0))

if A_score > B_score:
    print("YJ Win!")
elif A_score < B_score:
    print("HG Win!")
else:
    print("Both Win!")
