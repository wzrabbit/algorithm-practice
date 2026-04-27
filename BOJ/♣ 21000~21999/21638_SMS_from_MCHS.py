t1, v1 = map(int, input().split())
t2, v2 = map(int, input().split())

if t2 < 0 and v2 >= 10:
    print("A storm warning for tomorrow! Be careful and stay home if possible!")
    exit()

if t1 > t2:
    print("MCHS warns! Low temperature is expected tomorrow.")
    exit()

if v1 < v2:
    print("MCHS warns! Strong wind is expected tomorrow.")
    exit()

print("No message")
