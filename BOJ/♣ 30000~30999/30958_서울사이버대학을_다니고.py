N = int(input())
sentence = input()
occur_count = [0] * 26

for cur in sentence:
    if 'a' <= cur <= 'z':
        occur_count[ord(cur) - ord('a')] += 1

print(max(occur_count))
