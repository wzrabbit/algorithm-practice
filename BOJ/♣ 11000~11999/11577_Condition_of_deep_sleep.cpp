#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    int toggle_count = 0;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        int real_value = (cur + q.size()) % 2;

        if (real_value == 1) {
            if (i + K - 1 > N) {
                cout << "Insomnia";
                return 0;
            }

            q.push(i + K - 1);
            toggle_count += 1;
        }

        if (!q.empty() && q.front() == i) {
            q.pop();
        }
    }

    cout << toggle_count;
}
