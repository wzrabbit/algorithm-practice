#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N <= 5) {
        cout << -1;
        return 0;
    }

    cout << "1 0 1 1 ";

    for (int i = 0; i < N - 4; i++) {
        cout << "0 ";
    }
}