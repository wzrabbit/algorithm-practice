#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll land[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> land[i];

    cin >> M;
    ll score = 0;
    sort(land, land + N, greater<ll>());

    for (int i = 0; i < N; i++) {
        if (M >= land[i]) {
            M -= land[i];
            score += land[i] * land[i];
        } else if (M > 0) {
            score += M * M;
            break;
        } else
            break;
    }

    cout << score;
}