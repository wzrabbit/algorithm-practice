A = list(map(int, input().split(":")))
B = list(map(int, input().split(":")))

A = A[0] * 3600 + A[1] * 60 + A[2]
B = B[0] * 3600 + B[1] * 60 + B[2]

gap = (B + 86400 - A) % 86400

if gap == 0:
    gap += 86400

hours = str(gap // 3600).zfill(2)
minutes = str(gap % 3600 // 60).zfill(2)
seconds = str(gap % 60).zfill(2)

print(f"{hours}:{minutes}:{seconds}")
