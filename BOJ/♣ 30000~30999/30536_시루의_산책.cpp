#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

Point points[3001];
bool can_mark[3001];
int locations[3001];
int ranges[3001];
bool visited[3001];
int N, M;

void mark(int location, int range, bool is_siru) {
    for (int i = 1; i <= N; i++) {
        if ((points[i].x - points[location].x) *
                    (points[i].x - points[location].x) +
                (points[i].y - points[location].y) *
                    (points[i].y - points[location].y) <=
            range * range) {
            can_mark[i] = is_siru;
        }
    }
}

int get_max_siru_mark_count() {
    int max_siru_mark_count = 0;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (can_mark[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        max_siru_mark_count += 1;

        mark(cur, ranges[0], true);

        for (int i = 1; i <= N; i++) {
            if (can_mark[i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return max_siru_mark_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 1; i <= M; i++) {
        cin >> locations[i];
    }

    for (int i = 0; i <= M; i++) {
        cin >> ranges[i];
    }

    fill(can_mark + 1, can_mark + N + 1, true);

    for (int i = 1; i <= M; i++) {
        mark(locations[i], ranges[i], false);
    }

    cout << get_max_siru_mark_count();
}
