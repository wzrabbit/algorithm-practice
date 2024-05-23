#include <iostream>
#define INF 1'000'000'000'000
typedef long long ll;
using namespace std;

ll crosswalk[100001];
ll left_path_prefix[100001];
ll right_path_prefix[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> crosswalk[i];
    }

    for (int i = 1; i <= N - 1; i++) {
        cin >> left_path_prefix[i];
        left_path_prefix[i] += left_path_prefix[i - 1];
    }

    for (int i = 1; i <= N - 1; i++) {
        cin >> right_path_prefix[i];
        right_path_prefix[i] += right_path_prefix[i - 1];
    }

    ll best_dist = INF;
    ll best_crosswalk_index = -1;

    for (int i = 1; i <= N; i++) {
        ll cur_dist = left_path_prefix[i - 1] +
                      right_path_prefix[N - 1] -
                      right_path_prefix[i - 1] +
                      crosswalk[i];

        if (cur_dist < best_dist) {
            best_dist = cur_dist;
            best_crosswalk_index = i;
        }
    }

    cout << best_crosswalk_index << ' ' << best_dist;
}
