import sys
cases = int(sys.stdin.readline())
set_ = 0

for _ in range(cases):
    input_ = sys.stdin.readline().strip().split()
    command = input_[0]
    if len(input_) == 1:
        input_.append(-1)
    num = int(input_[1])

    if command == 'add':
        set_ |= 1 << num
    elif command == 'remove':
        set_ &= ~(1 << num)
    elif command == 'check':
        if set_ & 1 << num:
            print(1)
        else:
            print(0)
    elif command == 'toggle':
        set_ ^= 1 << num
    elif command == 'all':
        set_ = (1 << 21) - 1
    else:
        set_ = 0
