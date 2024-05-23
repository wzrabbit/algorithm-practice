input()
arr = sorted(list(set(map(int, input().split()))))

print(*arr, sep='\n')

