#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c, p;
};

struct RC {
    int r, c;
};

bool operator<(const Loc &a, const Loc &b) {
    return a.p < b.p;
}

char grid[1002][1002];
int power[1002][1002];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;
int life, delay;

void simulate_spreading() {
    priority_queue<Loc> pq;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '*') {
                pq.push({r, c, life});
                power[r][c] = life;
            }
        }
    }

    while (!pq.empty()) {
        Loc cur = pq.top();
        pq.pop();

        if (cur.p < power[cur.r][cur.c]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            int next_power;

            if (grid[r][c] == '#') {
                next_power = cur.p - 1 - delay;
            } else {
                next_power = cur.p - 1;
            }

            if (next_power > power[r][c]) {
                power[r][c] = next_power;
                pq.push({r, c, next_power});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int _, __;

    cin >> R >> C;
    cin >> life >> delay >> _ >> __;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    fill(&power[1][1], &power[R][C + 1], -1);

    simulate_spreading();

    vector<RC> answer;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (power[r][c] == -1) {
                answer.push_back({r, c});
            }
        }
    }

    if (answer.size() == 0) {
        cout << -1;
        return 0;
    }

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].r << ' ' << answer[i].c << '\n';
    }
}
