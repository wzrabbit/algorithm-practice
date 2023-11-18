#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int before_l, before_r;
    cin >> before_l >> before_r;

    int fun = 0;

    if (before_l == before_r && before_l != 0) {
        fun += 1;
    }

    for (int i = 1; i <= N - 1; i++) {
        int cur_l, cur_r;
        cin >> cur_l >> cur_r;

        if (before_l == cur_l && cur_l != 0) {
            fun += 1;
        }

        if (before_r == cur_r && cur_r != 0) {
            fun += 1;
        }

        if (cur_l == cur_r && cur_l != 0) {
            fun += 1;
        }

        before_l = cur_l;
        before_r = cur_r;
    }

    cout << fun;
}