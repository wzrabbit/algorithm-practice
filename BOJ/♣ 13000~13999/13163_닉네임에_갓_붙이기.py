n = int(input())

for _ in range(n):
    nick = input().split()
    nick[0] = 'god'
    print(''.join(nick))