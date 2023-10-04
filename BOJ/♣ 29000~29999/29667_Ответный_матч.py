A1, B1 = map(int, input().split(":"))
B2, A2 = map(int, input().split(":"))

if A1 >= B2 and B1 >= A2:
    print("YES")
else:
    print("NO")
