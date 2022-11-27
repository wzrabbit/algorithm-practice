def V8_to_number(value):
    value = list(map(int, value.split('.')))
    for i in range(8):
        value[i] = bin(value[i])[2:].zfill(8)
    value = int(''.join(value), 2)
    return value
    

def number_to_V8(value):
    value = int(value)
    value = bin(value)[2:].zfill(64)
    value = [value[i : i + 8] for i in range(0, 64, 8)]
    for i in range(8):
        value[i] = str(int(value[i], 2))
    value = '.'.join(value)
    return value
    

T = int(input())
for _ in range(T):
    query, value = input().split()
    
    if query == '1':
        print(V8_to_number(value))
    else:
        print(number_to_V8(value))
