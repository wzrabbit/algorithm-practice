N, S = input().split()
N = int(N)
appeared = set()
trashed_count = 0
result = ''

for i in range(len(S)):
    if S[i] in appeared:
        trashed_count += 1
    else:
        result += S[i]
        appeared.add(S[i])
        
result += str(trashed_count + 4)
result = str(1906 + N) + result
result = result[::-1]
result = 'smupc_' + result

print(result)
