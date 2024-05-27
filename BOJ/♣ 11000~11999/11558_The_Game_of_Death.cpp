#include <iostream>
using namespace std;

int next_no[10001];
bool visited[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> next_no[i];
            visited[i] = false;
        }

        int answer = 0;
        int cur = 1;

        while (!visited[cur] && cur != N) {
            answer += 1;
            visited[cur] = true;
            cur = next_no[cur];
        }

        if (cur == N) {
            cout << answer << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
