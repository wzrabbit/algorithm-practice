T = int(input())

for _ in range(T):
    word = input()
    vowel_count = sum(word.count(cur) for cur in 'aeiou')

    print(f'The number of vowels in {word} is {vowel_count}.')
