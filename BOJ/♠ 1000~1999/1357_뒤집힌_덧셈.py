def rev(num):
    return int(str(num)[::-1])


A, B = map(int, input().split())
print(rev(rev(A) + rev(B)))
