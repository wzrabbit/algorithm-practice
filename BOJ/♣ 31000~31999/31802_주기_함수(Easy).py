N = int(input())
arr = list(map(int, input().split()))
sum_arr = sum(arr)

start, end = map(int, input().split())
loops = (end - start) // N

start = (start + N * 10**9) % N
end = (end + N * 10**9) % N

answer = loops * sum_arr

if start <= end:
    answer += sum(arr[start:end])
else:
    answer += sum_arr - sum(arr[end:start])

print(answer)
