text = input()
for cur in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
    if cur not in text:
        print(cur)
        break