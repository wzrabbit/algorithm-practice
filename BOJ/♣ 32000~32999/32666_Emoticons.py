def convert_single_emotion(*text):
    min_index = 10 ** 10
    selected_emoticon = ''

    for emoticon in emoticons:
        index = text.find(emoticon)

        if index != -1 and index < min_index:
            min_index = index
            selected_emoticon = emoticon

    if selected_emoticon == '':
        return False
    
    text = text.replace(selected_emoticon, '☯', 1)
    return text

S = input()
symbols = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ '
emoticons = [':)', ':-)', ':-(', ';-)', 'xD', '^_^', '-_-', '^o^', '^^;', '(..)']
answer_min = 10 ** 10
answer_max = 0

for i in range(len(symbols)):
    for j in range(len(symbols)):
        text = S.replace(symbols[i], symbols[j])

        while True:
            min_index = 10 ** 10
            selected_emoticon = ''
            for emoticon in emoticons:
                index = text.find(emoticon)

                if index != -1 and index < min_index:
                    min_index = index
                    selected_emoticon = emoticon

            if selected_emoticon == '':
                break
            
            text = text.replace(selected_emoticon, '☯', 1)
        
        answer_min = min(answer_min, len(text))
        answer_max = max(answer_max, len(text))

print(answer_min, answer_max)
