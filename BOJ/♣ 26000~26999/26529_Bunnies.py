fibo = [1, 1]

for i in range(2, 46):
    fibo.append(fibo[-1] + fibo[-2])

T = int(input())

for _ in range(T):
    N = int(input())
    print(fibo[N])
