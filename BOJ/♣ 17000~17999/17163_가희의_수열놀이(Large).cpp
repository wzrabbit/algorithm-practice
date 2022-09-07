#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int segtree[4000000];

int update(int start, int end, int idx, int target, int value) {
    if (target < start || target > end)
        return segtree[idx];

    if (start == end)
        return segtree[idx] = value;

    int mid = (start + end) / 2;
    return segtree[idx] = min(
               update(start, mid, idx * 2 + 1, target, value),
               update(mid + 1, end, idx * 2 + 2, target, value));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q, mod;
    cin >> Q >> mod;

    vector<stack<int, vector<int>>> loc;
    stack<int> st;

    if (mod > Q) {
        while (Q--) {
            int q, x;
            cin >> q;

            if (q == 1)
                cin >> x;
            else if (q == 3)
                cout << -1 << '\n';
        }

        return 0;
    }

    loc.resize(mod);
    fill(&segtree[0], &segtree[mod * 4 + 1], -1);

    while (Q--) {
        int q, x;
        cin >> q;

        if (q == 1) {
            cin >> x;
            x %= mod;

            loc[x].push(st.size());
            update(0, mod - 1, 0, x, st.size());
            st.push(x);
        } else if (q == 2) {
            if (st.size() == 0)
                continue;

            int popped = st.top();
            st.pop();
            loc[popped].pop();

            if (loc[popped].size() == 0)
                update(0, mod - 1, 0, popped, -1);
            else
                update(0, mod - 1, 0, popped, loc[popped].top());
        } else if (q == 3) {
            if (segtree[0] == -1)
                cout << -1 << '\n';
            else
                cout << st.size() - segtree[0] << '\n';
        }
    }
}