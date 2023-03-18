#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, M;
    cin >> R >> C >> M;

    if (R + C > M + 1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << r + c - 1 << ' ';
        }

        cout << '\n';
    }
}