#include <iostream>
#include <set>
using namespace std;

int grundy[5001] = {0, 0, 1};

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

    for (int i = 3; i <= 5000; i++) {
        grundy[i] = mex(i);
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (grundy[N] > 0) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
}
