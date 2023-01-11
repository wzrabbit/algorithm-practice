#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string S;
    cin >> N >> S;

    stack<char> st;
    int max_level = 0;

    for (int i = 0; i < N; i++) {
        st.push(S[i]);

        if (st.size() >= 2) {
            char first = st.top();
            st.pop();
            char second = st.top();

            if (first != second) {
                st.pop();
            } else {
                st.push(first);
            }
        }

        max_level = max(max_level, (int)st.size());
    }

    if (st.size() > 0) {
        cout << -1;
    } else {
        cout << max_level;
    }
}