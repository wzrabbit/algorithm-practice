#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    stack<int> S;
    int answer = N - 1;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        while (!S.empty() && S.top() < cur) {
            S.pop();

            if (!S.empty()) {
                answer += 1;
            }
        }

        S.push(cur);
    }

    cout << answer;
}
