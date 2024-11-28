def is_prime(num):
    i = 2

    while i * i <= num:
        if num % i == 0:
            return False
        i += 1

    return True

word = input()
word_sum = 0

for cur in word:
    if cur >= 'a' and cur <= 'z':
        word_sum += ord(cur) - ord('a') + 1
    else:
        word_sum += ord(cur) - ord('A') + 27

if is_prime(word_sum):
    print("It is a prime word.")
else:
    print("It is not a prime word.")
