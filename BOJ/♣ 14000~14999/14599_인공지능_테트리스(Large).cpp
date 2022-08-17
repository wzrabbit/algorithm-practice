#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct q_data {
    int lv, r, c;
};

struct block {
    int r, c;
};

int board[20][10];
int block_cnt[20];
bool visited[19][20][10];
int max_score = 0;

int tetr_R[19][4] = {
    {0, 0, 1, 2},  // ㄴ
    {0, 0, 0, 1},
    {0, 1, 2, 2},
    {0, 1, 1, 1},

    {0, 0, 1, 2},  // ㄱ
    {0, 1, 1, 1},
    {0, 1, 2, 2},
    {0, 0, 0, 1},

    {0, 1, 2, 3},  // I
    {0, 0, 0, 0},

    {0, 0, 1, 1},  // ㅁ

    {0, 1, 1, 2},  // z 거꾸로
    {0, 0, 1, 1},

    {0, 1, 1, 2},  // z
    {0, 0, 1, 1},

    {0, 1, 1, 1},  // ㅗ
    {0, 1, 1, 2},
    {0, 0, 0, 1},
    {0, 1, 1, 2}};

int tetr_C[19][4] = {
    {0, 1, 0, 0},
    {0, 1, 2, 2},
    {1, 1, 0, 1},
    {0, 0, 1, 2},

    {0, 1, 1, 1},
    {2, 0, 1, 2},
    {0, 0, 0, 1},
    {0, 1, 2, 0},

    {0, 0, 0, 0},
    {0, 1, 2, 3},

    {0, 1, 0, 1},

    {0, 0, 1, 1},
    {1, 2, 0, 1},

    {1, 0, 1, 0},
    {0, 1, 1, 2},

    {1, 0, 1, 2},
    {0, 0, 1, 0},
    {0, 1, 2, 1},
    {1, 0, 1, 1}};

int dr[3] = {0, 1, 0};
int dc[3] = {1, 0, -1};

void alpha_go() {
    queue<q_data> q;
    for (int i = 0; i < 19; i++) {
        q.push({i, 0, 0});
        visited[i][0][0] = true;
    }

    while (q.size()) {
        q_data cur = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            block b1 = {cur.r + tetr_R[cur.lv][0] + dr[i], cur.c + tetr_C[cur.lv][0] + dc[i]};
            block b2 = {cur.r + tetr_R[cur.lv][1] + dr[i], cur.c + tetr_C[cur.lv][1] + dc[i]};
            block b3 = {cur.r + tetr_R[cur.lv][2] + dr[i], cur.c + tetr_C[cur.lv][2] + dc[i]};
            block b4 = {cur.r + tetr_R[cur.lv][3] + dr[i], cur.c + tetr_C[cur.lv][3] + dc[i]};

            // 이동 가능한 경우 이동
            if (b1.r >= 0 && b1.r < 20 && b1.c >= 0 && b1.c < 10 &&
                b2.r >= 0 && b2.r < 20 && b2.c >= 0 && b2.c < 10 &&
                b3.r >= 0 && b3.r < 20 && b3.c >= 0 && b3.c < 10 &&
                b4.r >= 0 && b4.r < 20 && b4.c >= 0 && b4.c < 10 &&
                board[b1.r][b1.c] == 0 && board[b2.r][b2.c] == 0 &&
                board[b3.r][b3.c] == 0 && board[b4.r][b4.c] == 0 &&
                !visited[cur.lv][cur.r + dr[i]][cur.c + dc[i]]) {
                q.push({cur.lv, cur.r + dr[i], cur.c + dc[i]});
                visited[cur.lv][cur.r + dr[i]][cur.c + dc[i]] = true;
            }
            // 아래가 막혔으면 점수계산
            if (i == 1 && (b1.r >= 20 || b2.r >= 20 || b3.r >= 20 || b4.r >= 20 ||
                           board[b1.r][b1.c] == 1 || board[b2.r][b2.c] == 1 ||
                           board[b3.r][b3.c] == 1 || board[b4.r][b4.c] == 1)) {
                block_cnt[b1.r - 1]++;
                block_cnt[b2.r - 1]++;
                block_cnt[b3.r - 1]++;
                block_cnt[b4.r - 1]++;

                int cur_score = 0;
                for (int j = 0; j < 20; j++) {
                    if (block_cnt[j] == 10)
                        cur_score++;
                }

                max_score = max(max_score, cur_score);

                block_cnt[b1.r - 1]--;
                block_cnt[b2.r - 1]--;
                block_cnt[b3.r - 1]--;
                block_cnt[b4.r - 1]--;
            }
        }
    }
}

int main() {
    for (int r = 0; r < 20; r++) {
        for (int c = 0; c < 10; c++) {
            scanf("%1d", &board[r][c]);

            if (board[r][c] == 1)
                block_cnt[r]++;
        }
    }

    alpha_go();
    printf("%d", max_score);
}