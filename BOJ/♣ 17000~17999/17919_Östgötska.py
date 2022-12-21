words = list(input().split())
success = 0

for word in words:
    if 'ae' in word:
        success += 1
        
if success * 100 // len(words) >= 40:
    print('dae ae ju traeligt va')
else:
    print('haer talar vi rikssvenska')