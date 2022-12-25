#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int visited[100001];

int get_next_mul_number(int num) {
    if (num == 0) return 0;

    num *= 2;
    int num_length = to_string(num).length();
    return num - pow(10, num_length - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, T, G;
    cin >> N >> T >> G;

    fill(visited, visited + 100001, -1);

    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == G) {
            cout << visited[cur];
            return 0;
        }

        if (visited[cur] == T) continue;

        if (cur != 99999 && visited[cur + 1] == -1) {
            visited[cur + 1] = visited[cur] + 1;
            q.push(cur + 1);
        }

        int next_mul_number = get_next_mul_number(cur);
        if (cur < 50000 && visited[next_mul_number] == -1) {
            visited[next_mul_number] = visited[cur] + 1;
            q.push(next_mul_number);
        }
    }

    cout << "ANG";
}