#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int prefix[1000001];

bool is_up_down_number(int num) {
    string S = to_string(num);
    bool has_up = false;
    bool has_down = false;

    if (num <= 99) {
        return false;
    }

    for (size_t i = 0; i < S.size() - 1; i++) {
        if (S[i] < S[i + 1]) {
            if (has_down) {
                return false;
            }
            has_up = true;
        } else if (S[i] > S[i + 1]) {
            if (!has_up) {
                return false;
            }
            has_down = true;
        } else {
            return false;
        }
    }

    if (!has_down) {
        return false;
    }

    return true;
}

void init() {
    for (int i = 1; i <= 1000000; i++) {
        if (is_up_down_number(i)) {
            prefix[i] = 1;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        prefix[i] += prefix[i - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    init();

    while (T--) {
        int start, end;
        cin >> start >> end;

        cout << prefix[end] - prefix[start - 1] << '\n';
    }
}
