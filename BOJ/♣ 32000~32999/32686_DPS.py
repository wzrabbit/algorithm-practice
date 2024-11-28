import sys
input = sys.stdin.readline

N, S, E = map(int, input().split())
damage = 0

for _ in range(N):
    R, A, D = map(int, input().split())
    cycle = R + A

    start_mod = S % cycle
    end_mod = E % cycle
    dps = D / A

    if start_mod > 0:
        damage += min(A, cycle - start_mod) * dps
    
    if end_mod >= R:
        damage += dps * (end_mod - R)

    full_start_time = S + cycle - start_mod
    full_end_time = E - end_mod

    if start_mod == 0:
        full_start_time -= cycle

    damage += (full_end_time - full_start_time) // cycle * D

print(damage / (E - S))

