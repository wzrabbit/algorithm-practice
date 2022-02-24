af, eu = list(map(int, input().split()))
af1 = af2 = eu1 = eu2 = 0

for _ in range(20):
    k, t = list(map(str, input().split()))
    t = float(t)
    if k == 'a' or k == 'A':
        af1 += t
        af2 += af * 0.1 / t
    else:
        eu1 += t
        eu2 += eu * 0.1 / t

af1 = af * 10 / af1
eu1 = eu * 10 / eu1

af1 = "{0:.2f}".format(af1)
eu1 = "{0:.2f}".format(eu1)
af2 = "{0:.2f}".format(af2)
eu2 = "{0:.2f}".format(eu2)

print('''Method 1
African: {} furlongs per hour
European: {} furlongs per hour
Method 2
African: {} furlongs per hour
European: {} furlongs per hour'''.format(af1, eu1, af2, eu2))
