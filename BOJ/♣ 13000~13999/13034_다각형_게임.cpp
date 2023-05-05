#include <iostream>
#include <set>
using namespace std;

int grundy[1001] = {0, 0, 1};

int mex(int dot) {
    set<int> values;

    for (int i = 0; i <= (dot - 2) / 2; i++) {
        values.insert(grundy[i] ^ grundy[dot - i - 2]);
    }

    for (int i = 0; i < values.size(); i++) {
        if (values.find(i) == values.end()) {
            return i;
        }
    }

    return values.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 3; i <= N; i++) {
        grundy[i] = mex(i);
    }

    if (grundy[N] > 0) {
        cout << 1;
    } else {
        cout << 2;
    }
}