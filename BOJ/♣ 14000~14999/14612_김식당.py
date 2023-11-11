import sys

input = sys.stdin.readline
print = sys.stdout.write

Q = list(map(int, input().split()))[0]
posts = []

for _ in range(Q):
    command = input().strip().split()

    if command[0] == "order":
        posts.append([int(command[1]), int(command[2])])
    elif command[0] == "sort":
        posts.sort(key=lambda x: x[1])
    else:
        target = int(command[1])
        for i in range(len(posts)):
            if posts[i][0] == target:
                posts.pop(i)
                break

    if len(posts) == 0:
        print("sleep\n")
        continue

    for i in range(len(posts)):
        print(f"{posts[i][0]} ")
    print("\n")
