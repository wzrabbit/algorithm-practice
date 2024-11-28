def get_grade(P):
    if 0 <= P <= 4:
        return 1
    
    if 4 < P <= 11:
        return 2

    if 11 < P <= 23:
        return 3
    
    if 23 < P <= 40:
        return 4
    
    if 40 < P <= 60:
        return 5
    
    if 60 < P <= 77:
        return 6
    
    if 77 < P <= 89:
        return 7
    
    if 89 < P <= 96:
        return 8
    
    return 9

N, K = map(int, input().split())
ranks = list(map(int, input().split()))

for rank in ranks:
    percentage = rank * 100 // N
    print(get_grade(percentage), end=' ')
