#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

int hive[2600][2600];
int history[2600][2600];
bool visited[2600][2600];
Pos pos[1005000];
int dr[6] = {-2, -1, 1, 2, 1, -1};
int dc[6] = {0, 1, 1, 0, -1, -1};
int r = 1298;
int c = 1300;
int number = 3;
int power = 1;

void draw_line(int nr, int nc, int repeat_count) {
    for (int i = 1; i <= repeat_count; i++) {
        r += nr;
        c += nc;
        hive[r][c] = number;
        pos[number] = {r, c};
        number += 1;
    }
}

void init_hive() {
    hive[1300][1300] = 1;
    hive[1298][1300] = 2;
    pos[1] = {1300, 1300};
    pos[2] = {1298, 1300};

    while (number <= 1'000'000) {
        draw_line(1, 1, power);
        draw_line(2, 0, power);
        draw_line(1, -1, power);
        draw_line(-1, -1, power);
        draw_line(-2, 0, power + 1);
        draw_line(-1, 1, power);
        power += 1;
    }
}

void traverse(int start, int end) {
    queue<Pos> q;
    q.push(pos[start]);
    visited[pos[start].r][pos[start].c] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (hive[cur.r][cur.c] == end) {
            return;
        }

        for (int i = 0; i < 6; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 0 || r >= 2600 || c < 0 || c >= 2600) {
                continue;
            }

            if (!visited[r][c]) {
                visited[r][c] = true;
                q.push({r, c});
                history[r][c] = hive[cur.r][cur.c];
            }
        }
    }
}

void print_shortest_path(int cur) {
    int r = pos[cur].r;
    int c = pos[cur].c;

    int next_hive_no = history[r][c];

    if (history[r][c] != 0) {
        print_shortest_path(next_hive_no);
    }

    cout << cur << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int A, B;
    cin >> A >> B;

    init_hive();
    traverse(A, B);
    print_shortest_path(B);
}
