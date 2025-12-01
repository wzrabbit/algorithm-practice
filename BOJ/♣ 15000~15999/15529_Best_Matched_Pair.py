N = int(input())
arr = list(map(int, input().split()))
answer = -1

for i in range(N - 1):
    for j in range(i + 1, N):
        calc_string = str(arr[i] * arr[j])
        success = True

        for k in range(len(calc_string) - 1):
            if int(calc_string[k]) + 1 != int(calc_string[k + 1]):
                success = False
                break

        if success:
            answer = max(answer, arr[i] * arr[j])

print(answer)
