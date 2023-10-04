#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int r, c;
};

vector<Point> answer;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    int r = -1;
    int c = -1;

    while (r != R - 1 || c != C - 1) {
        int dr[2], dc[2];

        if (R - r - 1 >= 2) {
            dr[0] = 1;
            dr[1] = 1;
        }

        if (R - r - 1 == 1) {
            dr[0] = 0;
            dr[1] = 1;
        }

        if (R - r - 1 == 0) {
            dr[0] = -1;
            dr[1] = 1;
        }

        if (C - c - 1 >= 2) {
            dc[0] = 1;
            dc[1] = 1;
        }

        if (C - c - 1 == 1) {
            dc[0] = 1;
            dc[1] = 0;
        }

        if (C - c - 1 == 0) {
            dc[0] = -1;
            dc[1] = 1;
        }

        vector<Point> current_answer;

        for (int i = 0; i < 2; i++) {
            r += dr[i];
            c += dc[i];

            current_answer.push_back({r, c});
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                answer.push_back(current_answer[j]);
            }
        }
    }

    cout << answer.size() << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].r << ' ' << answer[i].c << '\n';
    }
}
