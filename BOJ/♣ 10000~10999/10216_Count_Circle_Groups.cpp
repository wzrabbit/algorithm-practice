// Code By wizardrabbit - GL HF!

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct loc {
    int x, y, r;
};

int N;
loc enemy[3000];
bool visited[3000];

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (q.size()) {
        loc cur = enemy[q.front()];
        q.pop();

        for (int i = 0; i < N; i++) {
            loc next = enemy[i];

            if (!visited[i]) {
                int dist = (int)pow(abs(cur.x - next.x), 2) + (int)pow(abs(cur.y - next.y), 2);
                int cover = (int)pow(cur.r + next.r, 2);

                if (cover >= dist) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        fill(&visited[0], &visited[N], false);

        for (int i = 0; i < N; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            enemy[i] = {x, y, r};
        }

        int group = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                bfs(i);
                group++;
            }
        }

        cout << group << '\n';
    }
}