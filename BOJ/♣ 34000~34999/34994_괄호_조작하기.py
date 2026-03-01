import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())

for _ in range(N):
    S = list(input().strip())
    success = False

    for i in range(len(S)):
        if success:
            break

        for j in ('X', '(', ')', '[', ']', '{', '}'):
            
            if success:
                break

            T = S[:]

            if j != 'X':
                T[i] = j

            stack = []
            fail = False

            for k in range(len(S)):
                if T[k] in ('(', '[', '{'):
                    stack.append(T[k])
                    continue

                if len(stack) == 0:
                    fail = True
                    break

                if stack[-1] == '(' and T[k] == ')' or stack[-1] == '[' and T[k] == ']' or stack[-1] == '{' and T[k] == '}':
                    stack.pop()
                else:
                    fail = True
                    break

            if len(stack) == 0 and not fail:
                success = True
                print(f'YES ')

                if j == 'X':
                    print('0\n')
                else:
                    print('1\n')
            
                if j != 'X':
                    print(f'{i + 1} {j}\n')
        
    if not success:
        print('NO\n')
