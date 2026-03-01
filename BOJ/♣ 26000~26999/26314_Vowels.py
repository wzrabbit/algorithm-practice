N = int(input())

for _ in range(N):
    name = input()
    vowels = sum(1 for char in name if char in 'aeiou')
    consonants = len(name) - vowels
    
    print(name)
    print(1 if vowels > consonants else 0)
