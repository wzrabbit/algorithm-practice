#include <algorithm>
#include <iostream>
#include <queue>
#define INF 100
using namespace std;

struct Pos {
    int r, c;
};

struct PQData {
    int l, r, c, d;
};

bool operator<(const PQData &a, const PQData &b) {
    return a.d > b.d;
};

char grid[1002][1002];
int godzilla_visit_time[1002][1002];
int dist[5][1002][1002];
bool visited[1002][1002];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int R, C;
Pos destination;

Pos get_godzilla_position() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'G') {
                return {r, c};
            }
        }
    }

    return {1, 1};
}

void simulate_godzilla() {
    fill(&godzilla_visit_time[1][1], &godzilla_visit_time[R][C + 1], -1);
    fill(&visited[1][1], &visited[R][C + 1], false);
    Pos cur = get_godzilla_position();
    int time = 0;
    visited[cur.r][cur.c] = true;
    godzilla_visit_time[cur.r][cur.c] = 0;

    while (true) {
        bool acted = false;
        time += 1;

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i % 4];
            int c = cur.c + dc[i % 4];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c]) {
                continue;
            }

            if (i < 4 && grid[r][c] != 'R') {
                continue;
            }

            visited[r][c] = true;
            godzilla_visit_time[r][c] = time;
            cur.r = r;
            cur.c = c;
            acted = true;
            break;
        }

        if (!acted) {
            destination = {cur.r, cur.c};
            break;
        }
    }
}

void simulate_mech() {
    fill(&dist[0][1][1], &dist[4][R][C + 1], INF);
    priority_queue<PQData> pq;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'M') {
                dist[4][r][c] = 1;
                pq.push({4, r, c, 1});
            }
        }
    }

    while (!pq.empty()) {
        PQData cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.l][cur.r][cur.c]) {
            continue;
        }

        cout << "CUR: " << cur.l << ' ' << cur.r << ' ' << cur.c << ' ' << cur.d << "\n";

        if (cur.l != 4) {
            int r = cur.r + dr[cur.l];
            int c = cur.c + dc[cur.l];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            if (cur.d < dist[cur.l][r][c]) {
                dist[cur.l][r][c] = cur.d;
                pq.push({cur.l, r, c, cur.d});
            }

            continue;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            int attack_d = dist[cur.l][cur.r][cur.c];
            int move_d = attack_d + 1;

            if (grid[r][c] == 'R') {
                attack_d = max(attack_d, godzilla_visit_time[r][c]);
                move_d = max(move_d, godzilla_visit_time[r][c]);
            }

            if (move_d < dist[4][r][c]) {
                dist[4][r][c] = move_d;
                pq.push({4, r, c, move_d});
            }

            if (grid[r][c] != 'R' || godzilla_visit_time[r][c] != -1) {
                if (attack_d < dist[i][r][c]) {
                    dist[i][r][c] = attack_d;
                    pq.push({i, r, c, attack_d});
                }
            }
        }
    }
}

int get_answer() {
    int answer = INF;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int cur_dist = INF;

            for (int i = 0; i < 5; i++) {
                cur_dist = min(cur_dist, dist[i][r][c]);
            }

            if (cur_dist <= godzilla_visit_time[r][c]) {
                answer = min(answer, godzilla_visit_time[r][c]);
            }

            if (answer == 1) {
                cout << "UPD: " << r << ' ' << c << ' ' << answer << ' ' << cur_dist << '\n';
            }
        }
    }

    int destination_answer = INF;

    for (int i = 0; i < 5; i++) {
        destination_answer = min(destination_answer, dist[i][destination.r][destination.c]);
    }

    destination_answer = max(destination_answer, godzilla_visit_time[destination.r][destination.c]);

    cout << "D: " << answer << ' ' << destination_answer << endl;

    answer = min(answer, destination_answer);

    return answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> C >> R;

        for (int r = 1; r <= R; r++) {
            cin >> (grid[r]) + 1;
        }

        simulate_godzilla();
        simulate_mech();

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                cout << godzilla_visit_time[r][c] << '\t';
            }
            cout << '\n';
        }
        cout << "\n";

        for (int i = 0; i < 5; i++) {
            for (int r = 1; r <= R; r++) {
                for (int c = 1; c <= C; c++) {
                    cout << dist[i][r][c] << '\t';
                }
                cout << '\n';
            }
            cout << "\n";
        }
        cout << '\n';

        cout << get_answer() << '\n';
    }
}
