#include <iostream>
#include <stack>
using namespace std;

stack<int> S[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, P;
    cin >> N >> P;

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int n, p;
        cin >> n >> p;

        while (!S[n].empty() && S[n].top() > p) {
            answer += 1;
            S[n].pop();
        }

        if (S[n].empty() || S[n].top() != p) {
            S[n].push(p);
            answer += 1;
        }
    }

    cout << answer;
}
