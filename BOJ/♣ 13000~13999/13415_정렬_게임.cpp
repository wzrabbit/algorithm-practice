#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

struct query {
    int range, type;
};

int arr[100001];
deque<query> dq;
deque<int> ans;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int up, down;
        cin >> up >> down;

        while (dq.size() > 0 && dq.back().range <= up) dq.pop_back();
        dq.push_back({up, 0});

        while (dq.size() > 0 && dq.back().range <= down) dq.pop_back();
        dq.push_back({down, 1});
    }
    dq.push_back({0, 0});

    int l = 1;
    int r = dq.front().range;
    int idx = r;
    int last = r;

    sort(arr + 1, arr + last + 1);

    while (dq.size() >= 2) {
        query cur = dq.front();
        dq.pop_front();
        query nxt = dq.front();

        if (cur.type == 0) {
            while (idx > nxt.range) {
                ans.push_front(arr[r]);
                r--;
                idx--;
            }
        } else {
            while (idx > nxt.range) {
                ans.push_front(arr[l]);
                l++;
                idx--;
            }
        }
    }

    while (ans.size()) {
        cout << ans.front() << ' ';
        ans.pop_front();
    }

    for (int i = last + 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}