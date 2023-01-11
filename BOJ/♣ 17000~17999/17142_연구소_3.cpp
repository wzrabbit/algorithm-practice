#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 5000
using namespace std;

struct Loc {
    int r, c;
};

int grid[50][50];
int visited[50][50];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<int> start_locations;
vector<int> state;
int empty_count = 0;
int answer = INF;
int N, M;

void play_simulation() {
    fill(&visited[0][0], &visited[N - 1][N], -1);
    int empty_left = empty_count;
    queue<Loc> q;

    for (size_t i = 0; i < state.size(); i++) {
        int r = start_locations[state[i]] / N;
        int c = start_locations[state[i]] % N;

        visited[r][c] = 0;
        q.push({r, c});
    }

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (grid[cur.r][cur.c] == 0) {
            empty_left -= 1;
        }

        if (empty_left == 0) {
            answer = min(answer, visited[cur.r][cur.c]);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 0 && r < N && c >= 0 && c < N && visited[r][c] == -1 && grid[r][c] != 1) {
                visited[r][c] = visited[cur.r][cur.c] + 1;
                q.push({r, c});
            }
        }
    }
}

void make_combs(int cur_index) {
    state.push_back(cur_index);

    if (state.size() == M) {
        play_simulation();
    }

    for (int i = cur_index + 1; i < start_locations.size(); i++) {
        make_combs(i);
    }

    state.pop_back();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> grid[r][c];

            if (grid[r][c] == 2) {
                start_locations.push_back(r * N + c);
            }

            if (grid[r][c] == 0) {
                empty_count += 1;
            }
        }
    }

    for (size_t i = 0; i < start_locations.size(); i++) {
        make_combs(i);
    }

    if (answer == INF) {
        cout << -1;
    } else {
        cout << answer;
    }
}