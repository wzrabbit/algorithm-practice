#include <iostream>
typedef long long ll;
using namespace std;

ll height[250001];
int N, Q;

ll get_removable_nemo_count(int h, int c) {
    if (height[c] < h) {
        return 0;
    }

    int start = c + 1;
    int end = N;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (height[mid] >= h) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    ll nemo_count = end - c + height[c] - h + 1;
    return nemo_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }

    while (Q--) {
        int h, c;
        cin >> h >> c;

        cout << get_removable_nemo_count(h, c) << '\n';
    }
}
