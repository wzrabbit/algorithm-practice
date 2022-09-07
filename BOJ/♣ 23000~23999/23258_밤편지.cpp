#include <algorithm>
#include <iostream>
#define INF 60000000
using namespace std;

int floyd[301][301][301];

void floyd_copy(int idx, int N) {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++)
            floyd[idx][r][c] = floyd[idx - 1][r][c];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> floyd[0][r][c];
            if (floyd[0][r][c] == 0 && r != c)
                floyd[0][r][c] = INF;
        }
    }

    for (int m = 1; m <= N; m++) {
        floyd_copy(m, N);

        for (int s = 1; s <= N; s++) {
            for (int e = 1; e <= N; e++) {
                if (floyd[m][s][m] + floyd[m][m][e] < floyd[m][s][e])
                    floyd[m][s][e] = floyd[m][s][m] + floyd[m][m][e];
            }
        }
    }

    while (Q--) {
        int c, s, e;
        cin >> c >> s >> e;

        if (floyd[c - 1][s][e] < INF)
            cout << floyd[c - 1][s][e] << '\n';
        else
            cout << "-1\n";
    }
}