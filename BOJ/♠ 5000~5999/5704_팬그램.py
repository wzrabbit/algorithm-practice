while True:
    S = input()
    success = True
    
    if S == '*':
        break
    
    for i in range(26):
        cur = chr(97 + i)
        
        if cur not in S:
            success = False
            break
        
    if success:
        print('Y')
    else:
        print('N')