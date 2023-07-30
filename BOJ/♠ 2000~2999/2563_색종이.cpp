#include <iostream>
using namespace std;

bool paper[101][101];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int R, C;
        cin >> R >> C;

        for (int r = R; r < R + 10; r++) {
            for (int c = C; c < C + 10; c++) {
                paper[r][c] = true;
            }
        }
    }

    int area = 0;

    for (int r = 1; r <= 100; r++) {
        for (int c = 1; c <= 100; c++) {
            if (paper[r][c]) {
                area += 1;
            }
        }
    }

    cout << area;
}