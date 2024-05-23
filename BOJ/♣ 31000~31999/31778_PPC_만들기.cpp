#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    int r = S.size() - 1;

    for (int l = 0; l < S.size(); l++) {
        if (K == 0) {
            break;
        }

        if (S[l] == 'P') {
            continue;
        }

        while (l < r && S[r] == 'C') {
            r -= 1;
        }

        if (l >= r) {
            break;
        }

        K -= 1;
        swap(S[l], S[r]);
        r -= 1;
    }

    ll answer = 0;
    ll p_count = 0;
    ll c_count = 0;

    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] == 'C') {
            c_count += 1;
        }
    }

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'C') {
            c_count -= 1;
            continue;
        }

        p_count += 1;

        answer += (p_count - 1) * c_count;
    }

    cout << answer;
}
