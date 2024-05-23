N, Q = map(int, input().split())
arr = list(input())

def find_bundle_count(start, end):
    bundle_count = 1

    for i in range(start + 1, end + 1):
        if arr[i] != arr[i - 1]:
            bundle_count += 1
            
    return bundle_count

def transform(start, end):
    for i in range(start, end + 1):
        if arr[i] == 'Z':
            arr[i] = 'A'
            continue
        
        arr[i] = chr(ord(arr[i]) + 1)

for _ in range(Q):
    q, l, r = map(int, input().split())
    l -= 1
    r -= 1
    
    if q == 1:
        print(find_bundle_count(l, r))
    else:
        transform(l, r)
