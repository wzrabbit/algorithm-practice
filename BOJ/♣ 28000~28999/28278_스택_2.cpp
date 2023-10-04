#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    stack<int> S;

    for (int i = 1; i <= N; i++) {
        int command, X;
        cin >> command;

        switch (command) {
            case 1:
                cin >> X;
                S.push(X);
                break;
            case 2:
                if (S.empty()) {
                    cout << -1 << '\n';
                    break;
                }

                cout << S.top() << '\n';
                S.pop();
                break;
            case 3:
                cout << S.size() << '\n';
                break;
            case 4:
                cout << S.empty() << '\n';
                break;
            case 5:
                if (S.empty()) {
                    cout << -1 << '\n';
                    break;
                }

                cout << S.top() << '\n';
                break;
        }
    }
}
