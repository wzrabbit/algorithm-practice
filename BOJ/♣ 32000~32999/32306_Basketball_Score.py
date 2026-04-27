A, B, C = map(int, input().split())
D, E, F = map(int, input().split())

team1_score = A + B * 2 + C * 3
team2_score = D + E * 2 + F * 3

if team1_score > team2_score:
    print(1)
elif team1_score < team2_score:
    print(2)
else:
    print(0)
