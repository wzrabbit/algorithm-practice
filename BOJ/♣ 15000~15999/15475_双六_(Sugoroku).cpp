#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int max_combo = 0;
    int cur_combo = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (cur == 1) {
            cur_combo += 1;
        } else {
            cur_combo = 0;
        }

        max_combo = max(max_combo, cur_combo);
    }

    cout << max_combo + 1;
}