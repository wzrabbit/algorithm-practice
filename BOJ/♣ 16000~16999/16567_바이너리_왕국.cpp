#include <iostream>
using namespace std;

bool is_dirty[1000002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    int flip_needed = 0;

    for (int i = 1; i <= N; i++) {
        cin >> is_dirty[i];
    }

    for (int i = 1; i <= N; i++) {
        if (is_dirty[i] == true && is_dirty[i - 1] == false) {
            flip_needed += 1;
        }
    }

    while (Q--) {
        int query, location;
        cin >> query;

        if (query == 0) {
            cout << flip_needed << '\n';
        } else {
            cin >> location;

            if (is_dirty[location] == true) {
                continue;
            }

            int adjacent_dirty_count = 0;

            if (is_dirty[location - 1] == true) {
                adjacent_dirty_count += 1;
            }

            if (is_dirty[location + 1] == true) {
                adjacent_dirty_count += 1;
            }

            flip_needed += 1 - adjacent_dirty_count;
            is_dirty[location] = true;
        }
    }
}