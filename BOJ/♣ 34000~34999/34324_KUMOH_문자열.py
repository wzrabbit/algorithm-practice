N = int(input())
grid = [input().ljust(2000) for _ in range(N)]
answer = 0
KUMOH = "KUMOH"

def get_kumoh_count(text):
    index = 0
    count = 0

    for cur in text:
        if cur != ' ' and cur != KUMOH[index]:
            index = 0

        if cur == KUMOH[index]:
            index += 1
        
        if index == 5:
            index = 0
            count += 1
    
    return count

for i in range(2000):
    kumoh_arr = []

    for j in range(N):
        kumoh_arr.append(grid[j][i - j])
    
    kumoh_text = ''.join(kumoh_arr)
    answer += max(get_kumoh_count(kumoh_text), get_kumoh_count(kumoh_text[::-1]))

print(answer)
