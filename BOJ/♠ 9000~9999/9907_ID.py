A, B, C, D, E, F, G = map(int, list(input()))
calc = (A * 2 + B * 7 + C * 6 + D * 5 + E * 4 + F * 3 + G * 2) % 11

if calc == 0:
    print('J')
elif calc == 10:
    print('Z')
else:
    print(chr(64 + calc))
