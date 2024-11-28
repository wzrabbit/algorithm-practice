t1, e1, f1 = map(int, input().split())
t2, e2, f2 = map(int, input().split())

max_total = t1 * 3 + e1 * 20 + f1 * 120
mel_total = t2 * 3 + e2 * 20 + f2 * 120

if max_total > mel_total:
    print('Max')
elif max_total < mel_total:
    print('Mel')
else:
    print('Draw')
