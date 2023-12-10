#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N / 5; i++) {
            cout << "++++ ";
        }

        for (int i = 1; i <= N % 5; i++) {
            cout << "|";
        }

        cout << '\n';
    }
}