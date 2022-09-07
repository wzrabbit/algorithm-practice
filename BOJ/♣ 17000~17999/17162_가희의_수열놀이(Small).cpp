#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int cnt = 0;
vector<stack<int>> loc(100);
stack<int> st;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q, mod;
    cin >> Q >> mod;

    while (Q--) {
        int q, x;
        cin >> q;

        if (q == 1) {
            cin >> x;
            x = x % mod;

            loc[x].push(st.size());
            st.push(x);

            if (loc[x].size() == 1)
                cnt++;
        } else if (q == 2) {
            if (st.size() == 0)
                continue;

            int popped = st.top();
            st.pop();
            loc[popped].pop();

            if (loc[popped].size() == 0)
                cnt--;
        } else {
            if (cnt != mod)
                cout << -1 << '\n';
            else {
                int min_ = 200001;
                for (int i = 0; i < mod; i++) {
                    min_ = min(min_, loc[i].top());
                }

                cout << st.size() - min_ << '\n';
            }
        }
    }
}