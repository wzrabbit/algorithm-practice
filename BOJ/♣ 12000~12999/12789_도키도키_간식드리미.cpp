#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    stack<int> S;
    int order = 1;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (cur == order) {
            order += 1;

            while (!S.empty() && S.top() == order) {
                S.pop();
                order += 1;
            }

            continue;
        }

        S.push(cur);
    }

    if (order == N + 1) {
        cout << "Nice";
    } else {
        cout << "Sad";
    }
}