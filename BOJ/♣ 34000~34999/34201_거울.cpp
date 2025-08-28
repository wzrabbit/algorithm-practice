#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll A[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    ll answer = 0;

    for (int i = 1; i <= N / 2; i++) {
        answer -= A[i] * 2;
    }

    for (int i = N / 2 + 1; i <= N; i++) {
        answer += A[i] * 2;
    }

    if (N % 2 == 0) {
        answer += S;
    } else {
        answer -= S;
    }

    cout << answer;
}
