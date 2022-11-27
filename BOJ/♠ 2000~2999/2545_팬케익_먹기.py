T = int(input())

for _ in range(T):
    input()
    axis = list(map(int, input().split()))
    cut_chance = axis.pop()

    axis.sort(reverse=True)
    gap = axis[0] - axis[1]
    operation = min(cut_chance, gap)
    axis[0] -= operation
    cut_chance -= operation
    
    gap = axis[1] - axis[2]
    operation = min(cut_chance, gap * 2)
    axis[0] -= operation // 2
    axis[1] -= operation // 2
    if operation % 2 == 1:
        axis[1] -= 1
    cut_chance -= operation
        
    all_decrease_chance = cut_chance // 3
    partial_decrease_change = cut_chance % 3
    
    for i in range(3):
        axis[i] -= all_decrease_chance
    
    for i in range(2):
        if partial_decrease_change == 0:
            break
        axis[i] -= 1
        partial_decrease_change -= 1
        
    print(axis[0] * axis[1] * axis[2])