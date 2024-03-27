#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int r, c;
};

struct Answer {
    int p, t;
};

char grid[10][100001];
bool visited[10][100001];
int history[10][100001];
vector<Answer> answer;
int dr[2] = {-1, 1};
int R = 10, C;

void create_answer(int row, int col) {
    if (col > 1) {
        create_answer(row + history[row][col], col - 1);
    }

    if (history[row][col] == 1 || row == 0) {
        if (answer.size() >= 1 && answer[answer.size() - 1].p + answer[answer.size() - 1].t == col - 1) {
            answer[answer.size() - 1].t += 1;
        } else {
            answer.push_back({col - 1, 1});
        }
    }
}

void print_answer() {
    cout << answer.size() << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].p << ' ' << answer[i].t << '\n';
    }
}

void bfs() {
    visited[R - 1][0] = true;
    queue<Pos> q;
    q.push({R - 1, 0});

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.c == C - 1) {
            create_answer(cur.r, cur.c);
            break;
        }

        for (int i = 0; i < 2; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + 1;

            if (r == -1) {
                r = 0;
            }

            if (r == R) {
                r = R - 1;
            }

            if (!visited[r][c] && grid[r][c] == '.') {
                visited[r][c] = true;
                history[r][c] = cur.r - r;
                q.push({r, c});
            }
        }
    }

    print_answer();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> C;

    for (int r = 0; r < R; r++) {
        cin >> grid[r];
    }

    bfs();
}
