#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int x;
        cin >> x;
        cout << t << ": " << x << ' ' << (x * (x + 1) * (2 * x + 4)) / 12 << '\n';
    }
}