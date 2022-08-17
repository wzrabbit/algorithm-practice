N = int(input())
str_A = list(map(int, list(input())))
str_B = list(map(int, list(input())))
success = True

if N % 2 == 0:
    for i in range(len(str_A)):
        if str_A[i] != str_B[i]:
            success = False
            break
else:
    for i in range(len(str_A)):
        if str_A[i] == str_B[i]:
            success = False
            break

if success:
    print('Deletion succeeded')
else:
    print('Deletion failed')
