#include <iostream>
typedef long long ll;
using namespace std;

struct Cuboid {
    ll x1, x2, y1, y2, z1, z2;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Cuboid arrow, target;

    cin >> arrow.x1 >> arrow.x2 >> arrow.y1 >> arrow.y2 >> arrow.z1 >> arrow.z2;
    cin >> target.x1 >> target.x2 >> target.y1 >> target.y2 >> target.z1 >>
        target.z2;

    if (arrow.x2 <= target.x1 || target.x2 <= arrow.x1) {
        cout << -1;
        return 0;
    }

    if (arrow.y2 <= target.y1 || target.y2 <= arrow.y1) {
        cout << -1;
        return 0;
    }

    cout << arrow.z1 - target.z2 + 1;
}
