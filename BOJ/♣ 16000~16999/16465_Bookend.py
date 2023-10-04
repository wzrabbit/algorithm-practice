N, M, L = map(int, input().split())
books_length = sum(list(map(int, input().split())))

if M == books_length:
    print(0)
    exit()

if M < books_length:
    print(-1)
    exit()

if M < L:
    print(-1)
    exit()

if L <= books_length:
    print(1)
    exit()

if books_length + L <= M:
    print(1)
    exit()

print(-1)
