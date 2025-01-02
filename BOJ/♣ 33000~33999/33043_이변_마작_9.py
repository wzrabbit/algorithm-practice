import sys
input = sys.stdin.readline

def is_possible(memory):
    db = dict()
    
    for i in range(N):
        cur = arr[i]

        if cur not in db:
            db[cur] = 1
        else:
            db[cur] += 1

        if i >= memory:
            db[arr[i - memory]] -= 1

        if db[cur] == 5:
            return True
        
    return False
        

N = int(input())
arr = input().split()

start = 1
end = N
mid = None

while start <= end:
    mid = (start + end) // 2

    if is_possible(mid):
        end = mid - 1
    else:
        start = mid + 1

if start == N + 1:
    print(-1)
else:
    print(start)
