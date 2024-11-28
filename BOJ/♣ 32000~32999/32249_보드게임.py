import sys
input = sys.stdin.readline
debug = print
print = sys.stdout.write

def print_winner():
    alice_turn_count = alice_b_count
    bob_turn_count = bob_a_count

    if alice_bottom_b_count > 0:
        alice_turn_count -= 1

    if bob_bottom_a_count > 0:
        bob_turn_count -= 1

    if alice_turn_count <= bob_turn_count:
        print('Alice\n')
    else:
        print('Bob\n')

def swap(ar, ac, br, bc):
    global alice_bottom_b_count
    global bob_bottom_a_count

    ar -= 1
    ac -= 1
    br -= 1
    bc -= 1

    if ar == R - 1:
        if alice[ar][ac] == 'B':
            alice_bottom_b_count -= 1
        if bob[br][bc] == 'B':
            alice_bottom_b_count += 1

    if br == R - 1:
        if bob[br][bc] == 'A':
            bob_bottom_a_count -= 1
        if alice[ar][ac] == 'A':
            bob_bottom_a_count += 1

    alice[ar][ac], bob[br][bc] = bob[br][bc], alice[ar][ac]


R, C = map(int, input().split())
alice = []
bob = []
alice_b_count = 0
bob_a_count = 0
alice_bottom_b_count = 0
bob_bottom_a_count = 0

for i in range(R):
    alice.append(list(input()))
    alice_b_count += alice[-1].count('B')

    if i == R - 1:
        alice_bottom_b_count = alice[-1].count('B')

for _ in range(R):
    bob.append(list(input()))
    bob_a_count += bob[-1].count('A')

    if i == R - 1:
        bob_bottom_a_count = bob[-1].count('A')

Q = int(input())

print_winner()

for _ in range(Q):
    ar, ac, br, bc = map(int, input().split())

    swap(ar, ac, br, bc)
    print_winner()
