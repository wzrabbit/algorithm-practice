import sys
input = sys.stdin.readline

cases = int(input())
dict_ = {}

for i in range(cases):
    b, a = map(str, input().strip().split(' '))
    dict_[a] = b

word = list(input().strip())
for i in range(len(word)):
    word[i] = dict_[word[i]]

word = ''.join(word)
l, r = map(int, input().split(' '))
print(word[l - 1:r])
