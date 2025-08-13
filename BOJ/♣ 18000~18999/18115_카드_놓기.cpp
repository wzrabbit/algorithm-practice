#include <deque>
#include <iostream>
using namespace std;

int queries[1000001];
deque<int> dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> queries[i];
    }

    dq.push_back(1);

    for (int i = N - 1; i >= 1; i--) {
        if (queries[i] == 1) {
            dq.push_front(N - i + 1);
            continue;
        }

        if (queries[i] == 3) {
            dq.push_back(N - i + 1);
            continue;
        }

        int first = dq.front();
        dq.pop_front();
        dq.push_front(N - i + 1);
        dq.push_front(first);
    }

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        cout << cur << ' ';
    }
}
