#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    string S;
    cin >> N >> S;

    ll answer = 0;

    for (int i = 0; i < N; i++) {
        ll l = i - 1;
        ll r = i + 1;

        while (l >= 0 && S[l] != S[i]) {
            l -= 1;
        }

        while (r < N && S[r] != S[i]) {
            r += 1;
        }

        answer += (i - l) * (r - i) - 1;

        if (i - l > 1) {
            answer -= 1;
        }

        if (r - i > 1) {
            answer -= 1;
        }
    }

    cout << answer;
}
