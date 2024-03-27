N, Q = map(int, input().split())
songs = dict()

for _ in range(N):
    data = input().split()
    song = data[1]
    hint = "".join(data[2:5])

    if hint in songs:
        songs[hint] = "?"
    else:
        songs[hint] = song

for _ in range(Q):
    hint = input().replace(" ", "")

    if hint in songs:
        print(songs[hint])
    else:
        print("!")
