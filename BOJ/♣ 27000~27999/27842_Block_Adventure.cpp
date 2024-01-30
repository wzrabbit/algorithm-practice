#include <iostream>
typedef long long ll;
using namespace std;

ll arr[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        ll N, M, K;
        cin >> N >> M >> K;

        bool success = true;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= N - 1; i++) {
            if (arr[i] + K < arr[i + 1]) {
                M -= arr[i + 1] - arr[i] - K;

                if (M < 0) {
                    success = false;
                    break;
                }

                continue;
            }

            M += min(arr[i], arr[i] - arr[i + 1] + K);
        }

        if (success) {
            cout << "yEs\n";
        } else {
            cout << "nO\n";
        }
    }
}
