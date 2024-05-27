def decrypt(num):
    for i in range(8):
        for j in range(8):
            if 2 ** i + 2 ** j == num:
                return [i, j]
            
    return [-1, -1]

N = int(input())
commands = list(map(int, input().split()))
init = int(input())
keys = [0, 1, 2, 3, 4, 5, 6, 7]

for i in range(N):
    num = commands[i]
    a, b = decrypt(num)
    
    if a == -1 and b == -1:
        continue
    
    a_index = keys.index(a)
    b_index = keys.index(b)
    
    keys[a_index], keys[b_index] = keys[b_index], keys[a_index]
    
print(keys.index(init))
