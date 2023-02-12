while True:
    delay = int(input())
    if delay == 0:
        break
    
    text = input().replace(' ', '').upper()
    result_text = [''] * len(text)
    start_index = 0
    cur_index = 0
    
    for i in range(len(text)):
        if cur_index >= len(text):
            start_index += 1
            cur_index = start_index
            
        result_text[cur_index] = text[i]
        cur_index += delay
        
    print(''.join(result_text))
    
