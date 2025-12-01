#include <deque>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        deque<int> dq;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;
            dq.push_back(cur);
        }

        int prev_max = 0;
        int answer = 0;

        for (int i = 1; i <= N; i++) {
            int selected;

            if (dq.back() >= dq.front()) {
                selected = dq.front();
                dq.pop_front();
            } else {
                selected = dq.back();
                dq.pop_back();
            }

            if (selected >= prev_max) {
                answer += 1;
            }

            prev_max = max(prev_max, selected);
        }

        cout << "Case #" << t << ": " << answer << '\n';
    }
}
