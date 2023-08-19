#include <iostream>
using namespace std;

int score_grid[5][5];
int arr[5];
int best_schedule[2] = {0, 0};
int best_participants = -1;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < 5; c++) {
            cin >> arr[c];
        }

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (arr[i] == 1 && arr[j] == 1) {
                    score_grid[i][j] += 1;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            int cur_participants = score_grid[i][j];

            if (cur_participants > best_participants) {
                best_schedule[0] = i;
                best_schedule[1] = j;
                best_participants = cur_participants;
            }
        }
    }

    cout << best_participants << '\n';

    for (int i = 0; i < 5; i++) {
        if (i == best_schedule[0] || i == best_schedule[1]) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
}
