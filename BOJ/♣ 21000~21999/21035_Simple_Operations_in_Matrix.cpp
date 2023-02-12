#include <algorithm>
#include <iostream>
#include <string>
#define INF 999
using namespace std;

int matrix[51][51];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> matrix[r][c];
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        int pos, value;
        cin >> query >> pos >> value;

        if (query == "row") {
            for (int c = 1; c <= C; c++) {
                matrix[pos][c] += value;
            }
        } else {
            for (int r = 1; r <= R; r++) {
                matrix[r][pos] += value;
            }
        }
    }

    int sum = 0;
    int min_number = INF;
    int max_number = -INF;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            sum += matrix[r][c];
            max_number = max(max_number, matrix[r][c]);
            min_number = min(min_number, matrix[r][c]);
        }
    }

    cout << sum << ' ' << min_number << ' ' << max_number;
}