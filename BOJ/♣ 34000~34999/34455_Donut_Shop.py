D = int(input())
N = int(input())
exp = str(D) + ''.join(input() for _ in range(N * 2))

print(eval(exp))
