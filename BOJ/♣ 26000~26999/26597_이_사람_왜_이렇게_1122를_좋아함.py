import sys
input = sys.stdin.readline

Q = int(input())
left = -10 ** 18
right = 10 ** 18
result = 'Hmm...'
result_index = ''

for i in range(1, Q + 1):
    X, R = input().strip().split()
    X = int(X)

    if R == '^':
        left = max(left, X + 1)
    else:
        right = min(right, X - 1)

    if left == right and result != 'I got it!':
        result = 'I got it!'
        result_index = i

    if left > right:
        result = 'Paradox!'
        result_index = i
        break

if result == 'Hmm...':
    print('Hmm...')
else:
    print(result)
    print(result_index)
