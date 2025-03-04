T = int(input())

for t in range(1, T + 1):
    N = int(input())
    S = input()
    print(f"Data Set {t}:")
    print(f"{N + S.count("c") - S.count("b")}\n")
