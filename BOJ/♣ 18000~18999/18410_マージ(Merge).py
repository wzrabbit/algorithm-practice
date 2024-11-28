input()
A = list(map(int, input().split()))
B = list(map(int, input().split()))

print('\n'.join(list(map(str, sorted(A + B)))))
