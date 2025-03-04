import sys
input = sys.stdin.readline

def get_mex(mex_set):
    cur = 0

    while True:
        if cur not in mex_set:
            return cur
        cur += 1

N = int(input())
grundy = 0

for _ in range(N):
    A, B = map(int, input().split())
    mex_set = set()
    power = 1

    while power <= A:
        mex_set.add(A - power)
        power *= B

    mex = get_mex(mex_set)
    grundy ^= mex

if grundy == 0:
    print("Bob")
else:
    print("Alice")
