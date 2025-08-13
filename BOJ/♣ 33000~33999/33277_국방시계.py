N, M = map(int, input().split())

time = M * 24 * 60 // N
hours = str(time // 60).zfill(2)
minutes = str(time % 60).zfill(2)

print(f'{hours}:{minutes}')
