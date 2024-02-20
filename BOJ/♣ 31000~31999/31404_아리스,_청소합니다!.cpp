#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool has_dust[65][65];
char rule_A[66][66];
char rule_B[66][66];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, cur_R, cur_C, direction;
    cin >> R >> C >> cur_R >> cur_C >> direction;
    cur_R += 1;
    cur_C += 1;

    for (int r = 1; r <= R; r++) {
        cin >> (rule_A[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        cin >> (rule_B[r] + 1);
    }

    int moved_count = 0;
    int temp_count = 0;
    int kill = 0;

    fill(&has_dust[1][1], &has_dust[R][C + 1], true);

    while (true) {
        if (!has_dust[cur_R][cur_C]) {
            kill += 1;

            if (kill >= 100000) {
                break;
            }
        }

        int next_R = cur_R;
        int next_C = cur_C;
        int next_direction = direction;

        if (has_dust[cur_R][cur_C]) {
            moved_count += 1 + temp_count;
            temp_count = 0;
            next_direction = (direction + (rule_A[cur_R][cur_C] - '0')) % 4;
            has_dust[cur_R][cur_C] = false;
            kill = 0;
        } else {
            temp_count += 1;
            next_direction = (direction + (rule_B[cur_R][cur_C] - '0')) % 4;
        }

        next_R += dr[next_direction];
        next_C += dc[next_direction];

        if (next_R < 1 || next_R > R || next_C < 1 || next_C > C) {
            break;
        }

        cur_R = next_R;
        cur_C = next_C;
        direction = next_direction;
    }

    cout << moved_count;
}
