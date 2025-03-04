#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << "YES" << '\n';

        for (int i = 1; i <= N - 1; i++) {
            cout << i << ' ';
        }

        cout << N << '\n';
    }
}
