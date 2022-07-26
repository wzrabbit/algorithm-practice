N = int(input())
game = list(map(int, input().split()))

# 스프라그 - 그런디: 모든 게임의 그런디 수를 XOR한 값이 게임의 결과
result = game[0]
for i in range(1, N):
    result ^= game[i]

# 그런디 수 0 = 패배, else = 승리
if result == 0:
    print('cubelover')
else:
    print('koosaga')
