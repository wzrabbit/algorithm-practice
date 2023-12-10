#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int min_x = 9999;
    int min_y = 9999;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        if (y < min_y) {
            min_x = x;
            min_y = y;
        }
    }

    cout << min_x << ' ' << min_y;
}
