W, H = map(int, input().split())
n, w, h = map(int, input().split())
possible_count = (W // w) * (H // h)

if W >= w and H >= h:
    answer = n // possible_count
    if n % possible_count > 0:
        answer += 1
    print(answer)
else:
    print(-1)
