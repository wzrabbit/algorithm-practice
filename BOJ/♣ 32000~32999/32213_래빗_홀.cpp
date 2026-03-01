#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int grundy = 1;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;
            grundy = grundy ^ cur ^ 1;
        }

        if (grundy == 0) {
            cout << "tweede\n";
        } else {
            cout << "eerste\n";
        }
    }
}
