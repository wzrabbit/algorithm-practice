#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int r, c;
        cin >> r >> c;

        if (((r - 1) ^ (c - 1)) > 0) {
            cout << "jinseo\n";
            cout << min(r, c) << ' ' << min(r, c) << '\n';
        } else {
            cout << "dohoon\n";
        }
    }
}
