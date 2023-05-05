#include <iostream>
using namespace std;

int stones[101];

int get_grundy(int count) {
    if (count % 2 == 0) {
        return count / 2 - 1;
    }

    return count / 2 + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> stones[i];
    }

    int grundy = get_grundy(stones[1]);

    for (int i = 2; i <= N; i++) {
        grundy ^= get_grundy(stones[i]);
    }

    if (grundy > 0) {
        cout << "koosaga";
    } else {
        cout << "cubelover";
    }
}