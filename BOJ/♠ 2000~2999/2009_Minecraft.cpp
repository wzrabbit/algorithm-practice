#include <algorithm>
#include <iostream>
using namespace std;

char H[102][102];
char R[102][102];
char C[102][102];
char result[102][102][102];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        cin >> (H[r] + 1);
    }

    for (int r = 1; r <= N; r++) {
        cin >> (R[r] + 1);
    }

    for (int r = 1; r <= N; r++) {
        cin >> (C[r] + 1);
    }

    fill(&result[1][1][1], &result[N][N][N + 1], '1');

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (H[r][c] == '0') {
                for (int i = 1; i <= N; i++) {
                    result[i][r][c] = '0';
                }
            }

            if (R[r][c] == '0') {
                for (int i = 1; i <= N; i++) {
                    result[r][i][c] = '0';
                }
            }

            if (C[r][c] == '0') {
                for (int i = 1; i <= N; i++) {
                    result[r][c][i] = '0';
                }
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (H[r][c] == '1') {
                bool success = false;

                for (int i = 1; i <= N; i++) {
                    if (result[i][r][c] == '1') {
                        success = true;
                        break;
                    }
                }

                if (!success) {
                    cout << "NO";
                    return 0;
                }
            }

            if (R[r][c] == '1') {
                bool success = false;

                for (int i = 1; i <= N; i++) {
                    if (result[r][i][c] == '1') {
                        success = true;
                        break;
                    }
                }

                if (!success) {
                    cout << "NO";
                    return 0;
                }
            }

            if (C[r][c] == '1') {
                bool success = false;

                for (int i = 1; i <= N; i++) {
                    if (result[r][c][i] == '1') {
                        success = true;
                        break;
                    }
                }

                if (!success) {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";

    for (int h = 1; h <= N; h++) {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                cout << result[h][r][c];
            }

            cout << '\n';
        }
    }
}