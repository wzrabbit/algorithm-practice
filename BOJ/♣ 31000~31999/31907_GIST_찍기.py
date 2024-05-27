N = int(input())

for _ in range(N):
    print('G' * N + '.' * (N * 3))

for _ in range(N):
    print('.' * N + 'I' * N + '.' * N + 'T' * N)
    
for _ in range(N):
    print('.' * (2 * N) + 'S' * N + '.' * N)
 