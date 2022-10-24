#include <iostream>
using namespace std;

int jump[200001];
int ans[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> jump[i];
    }

    ans[N] = 1;
    for (int i = N - 1; i >= 1; i--) {
        if (i + jump[i] + 1 <= N) {
            ans[i] = ans[i + jump[i] + 1] + 1;
        } else {
            ans[i] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
}