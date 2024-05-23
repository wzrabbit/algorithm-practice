T = int(input())

for _ in range(T):
    A, B = map(int, input().split())
    award = 0
    
    if A == 1:
        award += 500
    elif 2 <= A <= 3:
        award += 300
    elif 4 <= A <= 6:
        award += 200
    elif 7 <= A <= 10:
        award += 50
    elif 11 <= A <= 15:
        award += 30
    elif 16 <= A <= 21:
        award += 10
        
    if B == 1:
        award += 512
    elif 2 <= B <= 3:
        award += 256
    elif 4 <= B <= 7:
        award += 128
    elif 8 <= B <= 15:
        award += 64
    elif 16 <= B <= 31:
        award += 32
        
    award *= 10000
        
    print(award)
