import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    sentence = input().rstrip()
    score = 0
    assert(len(sentence) != 0)
    
    score += sentence.count('I')
    score += sentence.count('V') * 5
    score += sentence.count('X') * 10
    score += sentence.count('L') * 50
    score += sentence.count('C') * 100
    score += sentence.count('D') * 500
    score += sentence.count('M') * 1000
    
    print(f'{score}\n')