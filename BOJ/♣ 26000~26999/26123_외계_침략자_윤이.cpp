#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll height_cnt[300001];
ll laser_cnt = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, D;
    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        height_cnt[cur]++;
    }

    for (int i = 300000; i >= 1; i--) {
        if (D <= 0) break;
        if (height_cnt[i] == 0) continue;

        laser_cnt += height_cnt[i];
        height_cnt[i - 1] += height_cnt[i];
        height_cnt[i] = 0;
        D--;
    }

    cout << laser_cnt;
}