import sys
input = sys.stdin.readline
print = sys.stdout.write

def get_palindrome(size):
    return "a" + "b" * (size - 2) + "a"

def get_ax_string(size):
    return "a" + "x" * (size - 1)


N, K = map(int, input().split())

if N == 2 and K == 0:
    print("No")
    exit()

if K == 0:
    print("Yes\n")
    print("a" + "x" * (N - 2) + "a")
    exit()

if K == 1:
    print("Yes\n")
    print("a" * (N - 1) + "x")
    exit()

if K == N - 1:
    print("Yes\n")
    print("a" * N)
    exit()

for i in range(3, N + 1):
    if N % i == 0 and K == N // i - 1:
        print("Yes\n")
        print(f'{get_palindrome(i) * (N // i)}')
        exit()
    
for i in range(2, N + 1):
    if N % i == 0 and K == N // i:
        print("Yes\n")
        print(f"{get_ax_string(i) * (N // i)}")
        exit()

print("No")
