vowels = ('a', 'e', 'i', 'o', 'u')

def get_syllable(string):
    syllable = ""
    has_vowel = False
    success = False

    for cur in string:
        if cur in vowels:
            has_vowel = True
        
        if has_vowel and cur not in vowels:
            success = True
            break

        syllable += cur

    if not success:
        return None
    
    return syllable

A = input()
B = input()

A_syllable = get_syllable(A)
B_syllable = get_syllable(B)

if A_syllable == None or B_syllable == None:
    print('no such exercise')
    exit()

print(A_syllable + B_syllable)
