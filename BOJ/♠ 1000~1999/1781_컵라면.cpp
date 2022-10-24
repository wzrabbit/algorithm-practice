#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct item {
    int due, ramen;
};

bool operator<(item a, item b) {
    return a.due > b.due;
}

vector<item> shelf;
priority_queue<int> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int d, r;
        cin >> d >> r;
        shelf.push_back({d, r});
    }

    sort(shelf.begin(), shelf.end());
    int p = 0;
    int ans = 0;

    for (int i = N; i >= 1; i--) {
        while (p < N && shelf[p].due >= i) {
            q.push(shelf[p].ramen);
            p++;
        }

        if (q.size()) {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans;
}
