#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, previous;
    cin >> N >> previous;

    int state = 0;
    int zigzag = 1;

    for (int i = 1; i <= N - 1; i++) {
        int cur;
        cin >> cur;

        if (state == 0) {
            if (previous == cur) {
                continue;
            }

            if (previous < cur) {
                state = 1;
            } else {
                state = -1;
            }

            zigzag += 1;
            previous = cur;
            continue;
        }

        if (state == -1 && previous < cur) {
            zigzag += 1;
            state = 1;
        } else if (state == 1 && previous > cur) {
            zigzag += 1;
            state = -1;
        }

        previous = cur;
    }

    cout << zigzag;
}
