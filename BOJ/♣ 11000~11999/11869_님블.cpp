#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int grundy = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        grundy ^= cur;
    }

    if (grundy > 0) {
        cout << "koosaga";
    } else {
        cout << "cubelover";
    }
}