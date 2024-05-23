T = int(input())

for _ in range(T):
    N = int(input().split()[1])
    answer = []
    
    while True:
        if N == 0:
            break
        
        if N <= 9:
            answer.append(N)
            break
        
        str_N = str(N)
        first_digit = int(str_N[0])
        second_digit = int(str_N[1])
        num_len = len(str(N))
        run_number = None
        candidates = [
            int(str(first_digit) * num_len),
            int(str(first_digit - 1) * num_len),
            int('9' * (num_len - 1))
        ]
        candidates.sort(reverse=True)
        
        for i in candidates:
            if N - i >= 0:
                run_number = i
                break
            
        N -= run_number
        answer.append(run_number)
        
    print(len(answer))
    print(*answer)
