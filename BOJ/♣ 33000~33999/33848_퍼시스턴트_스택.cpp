#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    stack<int> S, history;

    while (Q--) {
        int query_no;
        cin >> query_no;
        int cur;

        switch (query_no) {
            case 1:
                cin >> cur;
                S.push(cur);
                history.push(-1);
                break;
            case 2:
                history.push(S.top());
                S.pop();
                break;
            case 3:
                cin >> cur;

                for (int i = 1; i <= cur; i++) {
                    if (history.top() == -1) {
                        S.pop();
                    } else {
                        S.push(history.top());
                    }
                    history.pop();
                }
                break;
            case 4:
                cout << S.size() << '\n';
                break;
            case 5:
                if (S.size() == 0) {
                    cout << -1 << '\n';
                } else {
                    cout << S.top() << '\n';
                }
        }
    }
}
