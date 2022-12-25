#include <algorithm>
#include <iostream>
#define SQRT 2237
using namespace std;

int min_factor[5000001];

void print_factor(int cur) {
    if (cur == 1) return;
    cout << min_factor[cur] << ' ';
    print_factor(cur / min_factor[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    for (int i = 2; i <= 5000000; i++) {
        min_factor[i] = i;
    }

    for (int i = 2; i <= SQRT; i++) {
        if (min_factor[i] != i) continue;

        for (int j = i; j <= 5000000; j += i) {
            min_factor[j] = min(min_factor[j], i);
        }
    }

    while (Q--) {
        int cur;
        cin >> cur;
        print_factor(cur);
        cout << '\n';
    }
}