#include <iostream>
#include <string>
using namespace std;

char grid[102][102];
string mobis = "MOBIS";
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    int mobis_count = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            for (int i = 0; i < 8; i++) {
                bool success = true;
                int cur_r = r;
                int cur_c = c;

                for (int j = 0; j < 5; j++) {
                    if (cur_r < 1 || cur_r > N || cur_c < 1 || cur_c > N) {
                        success = false;
                        break;
                    }

                    if (grid[cur_r][cur_c] != mobis[j]) {
                        success = false;
                        break;
                    }

                    cur_r += dr[i];
                    cur_c += dc[i];
                }

                if (success) {
                    mobis_count += 1;
                }
            }
        }
    }

    cout << mobis_count;
}
