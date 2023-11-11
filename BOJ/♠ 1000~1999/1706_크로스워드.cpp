#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char grid[23][23];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    string answer = "zzzzzzzzzzzzzzzzzzzzz";

    for (int r = 1; r <= R; r++) {
        string cur = "";

        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '#') {
                if (cur.length() >= 2 && cur < answer) {
                    answer = cur;
                }

                cur = "";
            } else {
                cur += grid[r][c];
            }
        }

        if (cur.length() >= 2 && cur < answer) {
            answer = cur;
        }
    }

    for (int c = 1; c <= C; c++) {
        string cur = "";

        for (int r = 1; r <= R; r++) {
            if (grid[r][c] == '#') {
                if (cur.length() >= 2 && cur < answer) {
                    answer = cur;
                }

                cur = "";
            } else {
                cur += grid[r][c];
            }
        }

        if (cur.length() >= 2 && cur < answer) {
            answer = cur;
        }
    }

    cout << answer;
}