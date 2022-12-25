#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int decreaser[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        fill(decreaser + 1, decreaser + N + 1, N);

        for (int i = 1; i <= N; i++) {
            ll x;
            cin >> x;
            cout << x * 1000000 + decreaser[x] << ' ';
            decreaser[x] -= 1;
        }
        cout << '\n';
    }
}