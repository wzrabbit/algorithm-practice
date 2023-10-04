input()
operations = list(map(int, input().split()))
position = sum(operations)

if position > 0:
    print("Right")
elif position < 0:
    print("Left")
else:
    print("Stay")
