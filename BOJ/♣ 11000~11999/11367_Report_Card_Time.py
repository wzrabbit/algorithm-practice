N = int(input())

for _ in range(N):
    name, score = input().split()
    score = int(score)
    
    print(name, end=" ")

    if 97 <= score <= 100:
        print("A+")
    elif 90 <= score <= 96:
        print("A")
    elif 87 <= score <= 89:
        print("B+")
    elif 80 <= score <= 86:
        print("B")
    elif 77 <= score <= 79:
        print("C+")
    elif 70 <= score <= 76:
        print("C")
    elif 67 <= score <= 69:
        print("D+")
    elif 60 <= score <= 66:
        print("D")
    else:
        print("F")
