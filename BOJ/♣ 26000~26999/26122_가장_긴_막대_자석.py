import sys
input = sys.stdin.readline

N = int(input())
magnet_string = input().strip()
max_combo = 0
prev_length = 0
cur_length = 0
cur_string = ''

for cur in magnet_string:
    if cur != cur_string:
        cur_string = cur
        prev_length = cur_length
        cur_length = 1
    else:
        cur_length += 1
    
    max_combo = max(max_combo, min(prev_length, cur_length))
    
print(max_combo * 2)