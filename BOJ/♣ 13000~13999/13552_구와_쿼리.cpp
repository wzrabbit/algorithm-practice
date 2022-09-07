#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int dot[100000][3];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, Q, x, y, z, r;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> dot[i][0] >> dot[i][1] >> dot[i][2];

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int cnt = 0;
        cin >> x >> y >> z >> r;

        for (int j = 0; j < N; j++) {
            ll xx = abs(dot[j][0] - x);
            ll yy = abs(dot[j][1] - y);
            ll zz = abs(dot[j][2] - z);

            ll dist = xx * xx + yy * yy + zz * zz;

            if (dist <= r * r)
                cnt++;
        }

        cout << cnt << '\n';
    }
}