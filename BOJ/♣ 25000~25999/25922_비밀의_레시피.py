import sys

flush = sys.stdout.flush

divisor = 10**9
input()

print(f"? {divisor}")
flush()

num = int(input())
answer = []

while num > 0:
    answer.append(str(num % divisor))
    num //= divisor

print(f"! {' '.join(answer)}")
flush()
