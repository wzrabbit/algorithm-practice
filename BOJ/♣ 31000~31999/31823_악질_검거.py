N, M = map(int, input().split())
streak_day_set = set()
infos = []

for _ in range(N):
    streak = input().split()
    handle = streak[-1]
    max_combo = 0
    combo = 0
    
    for i in range(M):
        if streak[i] == '.':
            combo += 1
        else:
            combo = 0
            
        max_combo = max(max_combo, combo)
        
    infos.append([max_combo, handle])
    streak_day_set.add(max_combo)
    
print(len(streak_day_set))

for a, b in infos:
    print(a, b)
