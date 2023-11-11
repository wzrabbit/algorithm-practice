#include <iostream>
using namespace std;

int prefix[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        prefix[i] = prefix[i - 1] + cur;
    }

    int worst_prefix = 0;
    int answer = max(0, prefix[M]);

    for (int i = M + 1; i <= N; i++) {
        worst_prefix = min(worst_prefix, prefix[i - M]);
        answer = max(answer, prefix[i] - worst_prefix);
    }

    cout << answer;
}