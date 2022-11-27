import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
arr = list(map(int, input().split()))

for i in range(N):
    print(f'{arr[i] % N + 1} ')
