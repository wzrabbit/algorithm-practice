#include <iostream>
using namespace std;

int matrix[2][100][100];
int answer[100][100];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R1, C1;
    cin >> R1 >> C1;

    for (int r = 0; r < R1; r++) {
        for (int c = 0; c < C1; c++) {
            cin >> matrix[0][r][c];
        }
    }

    int R2, C2;
    cin >> R2 >> C2;

    for (int r = 0; r < R2; r++) {
        for (int c = 0; c < C2; c++) {
            cin >> matrix[1][r][c];
        }
    }

    for (int r = 0; r < R1; r++) {
        for (int c = 0; c < C2; c++) {
            for (int i = 0; i < C1; i++) {
                answer[r][c] += matrix[0][r][i] * matrix[1][i][c];
            }
        }
    }

    for (int r = 0; r < R1; r++) {
        for (int c = 0; c < C2; c++) {
            cout << answer[r][c] << ' ';
        }

        cout << '\n';
    }
}