#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, L, Q;
    cin >> N >> L >> Q;
    int moved = 0;
    int left = 1;
    int right = L;

    while (Q--) {
        int nxt;
        cin >> nxt;

        if (left <= nxt && nxt <= right)
            continue;
        else if (right < nxt) {
            int gap = nxt - right;
            moved += gap;
            left += gap;
            right += gap;
        } else {
            int gap = left - nxt;
            moved += gap;
            left -= gap;
            right -= gap;
        }
    }

    cout << moved;
}