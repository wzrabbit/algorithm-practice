#include <iostream>
typedef long long ll;
using namespace std;

ll sum[1000001];
ll prefix[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            sum[j] += i;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        prefix[i] = prefix[i - 1] + sum[i];
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << prefix[N] << '\n';
    }
}
