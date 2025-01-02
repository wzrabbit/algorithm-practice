import sys
input = sys.stdin.readline

N, K, M = map(int, input().split())
rank_count = [[0, 0, 0, 0, 0] for _ in range(5)]
regular_scores = [0] * 5

for i in range(N):
    rank_1, rank_2, rank_3, rank_4, score_1, score_2, score_3, score_4 = map(int, input().split())

    rank_count[rank_1][1] += 1
    rank_count[rank_2][2] += 1
    rank_count[rank_3][3] += 1
    rank_count[rank_4][4] += 1

    regular_scores[rank_1] += score_1
    regular_scores[rank_2] += score_2
    regular_scores[rank_3] += score_3
    regular_scores[rank_4] += score_4

for i in range(-100, 101):
    for j in range(-100, i + 1):
        for k in range(-100, j + 1):
            l = -(i + j + k)

            if l > k or l < -100:
                continue

            scores = [0, 0, 0, 0, 0]

            for x in range(1, 5):
                scores[x] = regular_scores[x]
                scores[x] += rank_count[x][1] * i + rank_count[x][2] * j + rank_count[x][3] * k + rank_count[x][4] * l

            rank = 1

            for x in range(1, 5):
                if scores[K] < scores[x]:
                    rank += 1
                    continue

                if scores[K] == scores[x] and x < K:
                    rank += 1

            if rank == M:
                print(i, j, k, l)
                exit()

print(-1)
