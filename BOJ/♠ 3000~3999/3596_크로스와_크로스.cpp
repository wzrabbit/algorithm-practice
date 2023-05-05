#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int grundy[2001] = {0, 1, 1, 1};

int get_grundy(int len) {
    set<int> candidates;

    for (int i = 1; i <= len; i++) {
        candidates.insert(grundy[max(i - 3, 0)] ^ grundy[max(len - i - 2, 0)]);
    }

    for (int i = 0; i < candidates.size(); i++) {
        if (candidates.find(i) == candidates.end()) {
            return i;
        }
    }

    return candidates.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 4; i <= N; i++) {
        grundy[i] = get_grundy(i);
    }

    if (grundy[N] > 0) {
        cout << 1;
    } else {
        cout << 2;
    }
}