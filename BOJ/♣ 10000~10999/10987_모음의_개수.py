S = input()
vowel_count = 0

for cur in ('a', 'e', 'i', 'o', 'u'):
    vowel_count += S.count(cur)
    
print(vowel_count)
