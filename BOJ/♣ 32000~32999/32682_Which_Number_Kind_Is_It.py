import sys
import math
input = sys.stdin.readline

def is_perfect_square(N):
    root = int(math.sqrt(N))
    return root * root == N

T = int(input())


for _ in range(T):
    N = int(input())
    answer = ''

    if N % 2 == 1:
        answer += 'O'
    
    if N == 0 or is_perfect_square(N):
        answer += 'S'

    if answer == '':
        answer = 'EMPTY'

    print(answer)
