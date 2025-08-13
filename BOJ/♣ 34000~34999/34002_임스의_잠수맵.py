A, B, C = map(int, input().split())
B_ticket, C_ticket = map(int, input().split())
xp = int(input()) * 100
time = 0

current_ticket = "A"
ticket_duration = 0

while True:
    if xp >= 25000:
        print(time)
        break

    if ticket_duration == 0:
        if C_ticket > 0:
            C_ticket -= 1
            ticket_duration += 30
            current_ticket = "C"
            continue

        if B_ticket > 0:
            B_ticket -= 1
            ticket_duration += 30
            current_ticket = "B"
            continue

        current_ticket = "A"
        ticket_duration = 9999999999
        continue

    time += 1

    if current_ticket == "A":
        xp += A
    elif current_ticket == "B":
        xp += B
    else:
        xp += C

    if ticket_duration > 0:
        ticket_duration -= 1
