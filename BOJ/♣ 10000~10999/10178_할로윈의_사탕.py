T = int(input())

for _ in range(T):
    a, b = map(int, input().split())
    print(f"You get {a // b} piece(s) and your dad gets {a % b} piece(s).")
