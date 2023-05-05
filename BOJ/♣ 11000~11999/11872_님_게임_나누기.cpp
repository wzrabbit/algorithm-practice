#include <iostream>
using namespace std;

int get_grundy(int stone) {
    if (stone == 0) return 0;
    if (stone % 4 == 3) return stone + 1;
    if (stone % 4 == 0) return stone - 1;
    return stone;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int grundy = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        grundy ^= get_grundy(cur);
    }

    if (grundy > 0) {
        cout << "koosaga";
    } else {
        cout << "cubelover";
    }
}