def get_total_budget_price(limit):
    total_price = 0

    for i in range(N):
        total_price += min(arr[i], limit)

    return total_price


N = int(input())
arr = list(map(int, input().split()))
M = int(input())

start = 1
end = max(arr)
mid = None

while start <= end:
    mid = (start + end) // 2
    current_price = get_total_budget_price(mid)

    if current_price <= M:
        start = mid + 1
    else:
        end = mid - 1

print(end)
