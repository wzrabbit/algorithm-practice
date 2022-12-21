#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll pos[100001];
ll prefix[100001];

ll get_cost(ll start, ll end) {
    ll mid = (start + end) / 2;
    return abs(prefix[mid - 1] - prefix[start - 1] - pos[mid] * (mid - start)) +
           abs(prefix[end] - prefix[mid] - pos[mid] * (end - mid));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll num, road_len, fuel;
    cin >> num >> road_len >> fuel;

    for (int i = 1; i <= num; i++) {
        cin >> pos[i];
        prefix[i] = prefix[i - 1] + pos[i];
    }

    ll left = 1;
    ll right = 2;
    ll max_count = -1;

    while (right <= num) {
        if (get_cost(left, right) <= fuel) {
            max_count = max(max_count, right - left + 1);
            right += 1;
        } else {
            left += 1;
        }
    }

    cout << max_count;
}