import sys
input = sys.stdin.readline

n = int(input())
bin_n = bin(n)[2:]

if not '0' in bin_n:
    print('1')
    print(n)
else:
    max_ = 2 ** len(bin_n) - 1
    print('2')
    print(max_ ^ n, end=' ')
    print(n)
