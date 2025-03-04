#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 100'000'000
using namespace std;

struct History {
    int i, j, k, t;
};

struct Diff {
    int s, c;
};

int schedule[1001];
int patience[1001];
int answer[1001];
Diff L[1001], R[1001];
int dp[1001][2001][2];
History history[1001][2001][2];
int N, M, A, B;

void init_LR(int escape_count) {
    vector<int> work_count_L(M + 1), work_count_R(M + 1);

    for (int i = 1; i <= N - escape_count; i++) {
        work_count_L[schedule[i]] += 1;
    }

    for (int i = N - escape_count + 1; i <= N; i++) {
        work_count_R[schedule[i]] += 1;
    }

    for (int i = 1; i <= M; i++) {
        L[i] = {work_count_L[i], work_count_R[i]};
        R[i] = {work_count_L[i] - patience[i],
                max(0, patience[i] - work_count_L[i])};
    }
}

void update_answer(int start_col, int escape_count) {
    int replacer;
    vector<int> replace_L(M + 1), replace_R(M + 1);
    queue<int> L_elements;
    History cur = {M, start_col, 1, -1};

    while (true) {
        History nxt = history[cur.i][cur.j][cur.k];

        if (nxt.i == -1) {
            break;
        }

        int change_count = cur.j - nxt.j;
        int space_count = dp[cur.i][cur.j][cur.k] - dp[nxt.i][nxt.j][nxt.k];

        if (nxt.t == 1) {
            replace_L[cur.i] += space_count;
            replace_R[cur.i] += change_count;
        }

        if (nxt.t == 2) {
            if (space_count >= 0) {
                replace_L[cur.i] += space_count;
            } else {
                for (int i = 1; i <= -space_count; i++) {
                    L_elements.push(cur.i);
                }
            }
        }

        if (cur.k == 1 && nxt.k == 0) {
            replacer = cur.i;
        }

        cur = nxt;
    }

    int chance = A;

    for (int i = 1; i <= N - escape_count; i++) {
        if (replace_L[schedule[i]] > 0 && L_elements.size() > 0 && chance > 0) {
            replace_L[schedule[i]] -= 1;
            chance -= 1;

            answer[i] = L_elements.front();
            L_elements.pop();
        } else {
            answer[i] = schedule[i];
        }
    }

    for (int i = N - escape_count + 1; i <= N; i++) {
        if (replace_R[schedule[i]] > 0 && chance > 0) {
            replace_R[schedule[i]] -= 1;
            chance -= 1;
            answer[i] = replacer;
        } else {
            answer[i] = schedule[i];
        }
    }
}

bool is_escapable(int escape_count) {
    init_LR(escape_count);
    int chance = A + B;
    fill(&dp[0][0][0], &dp[M][chance][2], -INF);
    fill(&history[0][0][0], &history[M][chance][2], History{-1, -1, -1, -1});
    dp[0][0][0] = B;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= chance; j++) {
            for (int k = 0; k <= 1; k++) {
                if (j - L[i].c >= 0) {
                    int next_space = dp[i - 1][j - L[i].c][k] + L[i].s;

                    if (next_space > dp[i][j][k]) {
                        dp[i][j][k] = next_space;
                        history[i][j][k] = {i - 1, j - L[i].c, k, 1};
                    }
                }

                if (j - R[i].c >= 0 && j - R[i].c <= chance) {
                    int next_space = dp[i - 1][j - R[i].c][k] + R[i].s;

                    if (next_space > dp[i][j][1]) {
                        dp[i][j][1] = next_space;
                        history[i][j][1] = {i - 1, j - R[i].c, k, 2};
                    }
                }
            }
        }
    }

    for (int i = 0; i <= chance; i++) {
        if (dp[M][i][1] >= 0) {
            update_answer(i, escape_count);
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> A >> B;

    for (int i = 1; i <= N; i++) {
        cin >> schedule[i];
    }

    for (int i = 1; i <= M; i++) {
        cin >> patience[i];
    }

    int start = 0;
    int end = N;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_escapable(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << ' ';
    }
}
