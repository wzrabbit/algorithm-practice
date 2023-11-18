#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

struct Star {
    ll r, c, b;
};

Star stars[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int r, c, b;
        cin >> r >> c >> b;

        stars[i] = {r, c, b};
    }

    ll brightness = 0;

    int SR, SC, ER, EC;
    cin >> SR >> SC >> ER >> EC;

    for (int i = 1; i <= N; i++) {
        for (int r = SR; r <= ER; r++) {
            Star cur = stars[i];
            int s = cur.c - (cur.b - abs(cur.r - r) - 1);
            int e = cur.c + (cur.b - abs(cur.r - r) - 1);
            int m = (s + e) / 2;

            if (s > e) {
                continue;
            }

            if (m - 1 >= SC && s <= EC) {
                int left_s = max(s, SC);
                int left_e = min(m - 1, EC);
                int left_s_num = left_s - s + 1;
                int left_e_num = left_e - s + 1;

                brightness += (left_s_num + left_e_num) * (left_e_num - left_s_num + 1) / 2;
            }

            if (e >= SC && m <= EC) {
                int right_s = max(m, SC);
                int right_e = min(e, EC);
                int right_s_num = e - right_s + 1;
                int right_e_num = e - right_e + 1;

                brightness += (right_s_num + right_e_num) * (right_s_num - right_e_num + 1) / 2;
            }
        }
    }

    cout << brightness;
}
