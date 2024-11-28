#include <iostream>
using namespace std;

int score_prefix[3][10001];
int best_score[3][10001];
int time_prefix[3][10001];
int N, T;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> T;

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> score_prefix[i][j];
            score_prefix[i][j] += score_prefix[i][j - 1];
            best_score[i][j] = max(best_score[i][j - 1], score_prefix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> time_prefix[i][j];
            time_prefix[i][j] += time_prefix[i][j - 1];
        }
    }

    int answer = 0;

    for (int i = 0; i <= N; i++) {
        int l = 0;
        int r = N;

        while (r >= 0 && l <= N) {
            int left_time = T - time_prefix[0][i] - time_prefix[1][l] - time_prefix[2][r];

            if (left_time < 0) {
                r -= 1;
                continue;
            }

            int cur_score = best_score[0][i] + best_score[1][l] + best_score[2][r];
            answer = max(answer, cur_score);
            l += 1;
        }
    }

    cout << answer;
}
