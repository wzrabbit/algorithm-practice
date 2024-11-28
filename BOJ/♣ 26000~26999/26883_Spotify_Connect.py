N = int(input())
is_playing = False
play_duration = 0
last_play_time = 0

commands = []

for _ in range(N):
    time, device, query = input().split()
    time = int(time)

    if device == 'mobile':
        time += 100

    commands.append([time, device, query])

commands.sort(key=lambda x: x[0])

for i in range(N):
    time, device, query = commands[i]

    if query == 'play':
        if not is_playing:
            is_playing = True
            last_play_time = time
    else:
        if is_playing:
            is_playing = False
            play_duration += time - last_play_time

print(play_duration)
