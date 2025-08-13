#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool visited[1501][1501];

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int sum = A + B + C;

    if (sum % 3 != 0) {
        cout << 0;
        return 0;
    }

    visited[A][B] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(A, B));

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int a = cur.first;
        int b = cur.second;
        int c = sum - a - b;

        if (a < b && !visited[a + a][b - a]) {
            q.push(make_pair(a + a, b - a));
            visited[a + a][b - a] = true;
        }

        if (a > b && !visited[a - b][b + b]) {
            q.push(make_pair(a - b, b + b));
            visited[a - b][b + b] = true;
        }

        if (a < c && !visited[a + a][b]) {
            q.push(make_pair(a + a, b));
            visited[a + a][b] = true;
        }

        if (a > c && !visited[a - c][b]) {
            q.push(make_pair(a - c, b));
            visited[a - c][b] = true;
        }

        if (b < c && !visited[a][b + b]) {
            q.push(make_pair(a, b + b));
            visited[a][b + b] = true;
        }

        if (b > c && !visited[a][b - c]) {
            q.push(make_pair(a, b - c));
            visited[a][b - c] = true;
        }
    }

    cout << visited[sum / 3][sum / 3];
}
