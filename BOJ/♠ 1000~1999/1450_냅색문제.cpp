#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll arr[31];
vector<ll> L, R;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, C;
    cin >> N >> C;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < (1 << (N / 2)); i++) {
        ll cur = 0;

        for (int j = 1; j <= N / 2; j++) {
            if ((i & (1 << (j - 1))) > 0) {
                cur += arr[j];
            }
        }

        L.push_back(cur);
    }

    for (int i = 0; i < (1 << (N - N / 2)); i++) {
        ll cur = 0;

        for (int j = N / 2 + 1; j <= N; j++) {
            if ((i & (1 << (j - N / 2 - 1))) > 0) {
                cur += arr[j];
            }
        }

        R.push_back(cur);
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    ll answer = 0;

    for (size_t i = 0; i < L.size(); i++) {
        int start = 0;
        int end = (int)R.size() - 1;
        int mid;

        while (start <= end) {
            mid = (start + end) / 2;

            if (L[i] + R[mid] <= C) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        answer += end + 1;
    }

    cout << answer;
}
