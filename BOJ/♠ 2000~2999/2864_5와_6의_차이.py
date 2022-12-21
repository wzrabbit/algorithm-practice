A, B = input().split()
minimum = int(A.replace('6', '5')) + int(B.replace('6', '5'))
maximum = int(A.replace('5', '6')) + int(B.replace('5', '6'))

print(minimum, maximum)
