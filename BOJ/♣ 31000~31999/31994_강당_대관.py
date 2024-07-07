answer = ''
max_participant_count = 0

for _ in range(7):
    name, participant_count = input().split()
    participant_count = int(participant_count)

    if participant_count > max_participant_count:
        max_participant_count = participant_count
        answer = name

print(answer)
