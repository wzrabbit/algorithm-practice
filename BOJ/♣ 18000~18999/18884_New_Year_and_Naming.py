import sys
input = sys.stdin.readline
print = sys.stdout.write

a, b = map(int, input().split())
a_list = input().strip().split()
b_list = input().strip().split()
a_list.insert(0, a_list.pop())
b_list.insert(0, b_list.pop())

q = int(input())
for _ in range(q):
    n = int(input())
    print(a_list[n % len(a_list)] + b_list[n % len(b_list)] + '\n')
