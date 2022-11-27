N = int(input())
dance_set = set({'ChongChong'})

for _ in range(N):
    a, b = input().split(' ')
    if a in dance_set or b in dance_set:
        dance_set.add(a)
        dance_set.add(b)
        
print(len(dance_set))