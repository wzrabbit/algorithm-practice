T = int(input())

for _ in range(T):
    words = [input() for _ in range(3)]
    is_fix_free = True

    for i in range(2):
        for j in range(i + 1, 3):
            shorter_len = min(len(words[i]), len(words[j]))

            if words[i][:shorter_len] == words[j][:shorter_len]:
                is_fix_free = False

            if words[i][-shorter_len:] == words[j][-shorter_len:]:
                is_fix_free = False
    
    print('Yes' if is_fix_free else 'No')
