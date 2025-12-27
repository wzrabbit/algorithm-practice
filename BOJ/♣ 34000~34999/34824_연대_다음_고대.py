N = int(input())
arr = [input() for _ in range(N)]

if arr.index('yonsei') < arr.index('korea'):
    print('Yonsei Won!')
else:
    print('Yonsei Lost...')
