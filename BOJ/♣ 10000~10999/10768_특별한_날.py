M, D = int(input()), int(input())

if M == 1 or (M == 2 and D < 18):
    print('Before')
elif M >= 3 or (M == 2 and D > 18):
    print('After')
else:
    print('Special')
