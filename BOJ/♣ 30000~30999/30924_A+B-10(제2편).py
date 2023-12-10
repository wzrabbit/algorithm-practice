import sys
import random

input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush

A = -1
B = -1
B_list = list(range(1, 10001))
random.shuffle(B_list)

for i in range(1, 10000):
    print(f"? A {i}\n")
    flush()

    is_correct = int(input())

    if is_correct:
        A = i
        break

if A == -1:
    A = 10000

for i in range(9998):
    print(f"? B {B_list[i]}\n")
    flush()

    is_correct = int(input())

    if is_correct:
        B = B_list[i]
        break
if B == -1:
    B = B_list[-1]

print(f"! {A + B}")
flush()
