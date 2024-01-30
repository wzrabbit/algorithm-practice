#include <iostream>
typedef long long ll;
using namespace std;

ll castella[200001];
ll prefix[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> castella[i];
        ll cur_count = 1;

        while (castella[i] % 2 == 0) {
            castella[i] /= 2;
            cur_count *= 2;
        }

        prefix[i] = prefix[i - 1] + cur_count;
    }

    int Q;
    cin >> Q;

    while (Q--) {
        ll index;
        cin >> index;

        ll start = 1;
        ll end = N;
        ll mid;

        while (start <= end) {
            mid = (start + end) / 2;

            if (prefix[mid] < index) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        cout << castella[start] << '\n';
    }
}
