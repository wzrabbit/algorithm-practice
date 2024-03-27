import sys

input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    N = int(input())
    fruit = input().strip()
    result = input().strip()

    has_G = "G" in fruit
    has_O = "O" in fruit
    has_D = "D" in fruit
    fruit_kind = has_G + has_O + has_D
    question_count = fruit.count("?")

    if "D" in result:
        if result.count("D") != N:
            print("NO\n")
            continue

        if fruit_kind == 0:
            print("YES\n")
            print("G" * N)
            print("\n")
            continue

        if fruit_kind == 1:
            print("YES\n")

            if has_G:
                print("G" * N)
            elif has_O:
                print("O" * N)
            else:
                print("D" * N)

            print("\n")
            continue

        if fruit_kind + question_count < 3:
            print("NO\n")
            continue

        print("YES\n")

        for i in fruit:
            if i == "?":
                if not has_G:
                    print("G")
                    has_G = True
                elif not has_O:
                    print("O")
                    has_O = True
                else:
                    print("D")
                    has_D = True
            else:
                print(i)

        print("\n")
        continue

    if "W" not in result or "L" not in result:
        print("NO\n")
        continue

    win = "?"
    lose = "?"
    success = True

    for i in range(N):
        if result[i] == "W":
            if win == "?":
                win = fruit[i]
            elif win != fruit[i] and fruit[i] != "?":
                success = False
                break
        else:
            if lose == "?":
                lose = fruit[i]
            elif lose != fruit[i] and fruit[i] != "?":
                success = False
                break

    if win == "?" and lose == "?":
        win = "G"
        lose = "O"
    elif win == "?":
        if lose == "G":
            win = "D"
        elif lose == "O":
            win = "G"
        else:
            win = "O"
    elif lose == "?":
        if win == "G":
            lose = "O"
        elif win == "O":
            lose = "D"
        else:
            lose = "G"
    else:
        if not (
            (win == "G" and lose == "O")
            or (win == "O" and lose == "D")
            or (win == "D" and lose == "G")
        ):
            success = False

    if not success:
        print("NO\n")
        continue

    print("YES\n")

    for i in range(N):
        if result[i] == "L":
            print(lose)
        else:
            print(win)

    print("\n")
