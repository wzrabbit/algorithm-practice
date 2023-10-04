#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

struct Balloon {
    int i, v;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    deque<Balloon> dq;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        dq.push_back({i, cur});
    }

    for (int i = 1; i <= N; i++) {
        Balloon cur = dq.front();
        dq.pop_front();

        cout << cur.i << ' ';

        if (i == N) {
            break;
        }

        if (cur.v < 0) {
            for (int j = 1; j <= -cur.v; j++) {
                Balloon popped = dq.back();
                dq.pop_back();
                dq.push_front(popped);
            }
        } else {
            for (int j = 1; j < cur.v; j++) {
                Balloon popped = dq.front();
                dq.pop_front();
                dq.push_back(popped);
            }
        }
    }
}