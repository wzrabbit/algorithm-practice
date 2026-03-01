pawn_count, rook_pos, size = map(int, input().split())

if rook_pos <= pawn_count:
    print(1)
    exit()

if pawn_count == 1:
    print(2)
    exit()

if pawn_count == 2 and size > 3:
    print(3)
    exit()

if pawn_count == 2:
    print(4)
    exit()

print(5)
