A = bin(int(input()))[2:][-4:].zfill(4)
B = bin(int(input()))[2:][-4:].zfill(4)
C = bin(int(input()))[2:][-4:].zfill(4)
password = str(int(A + B + C, 2)).zfill(4)

print(password)
