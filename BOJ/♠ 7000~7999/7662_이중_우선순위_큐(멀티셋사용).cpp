#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        multiset<int> S;

        for (int i = 1; i <= N; i++) {
            char command;
            int value;
            cin >> command >> value;

            if (command == 'I') {
                S.insert(value);
                continue;
            }

            if (S.empty()) {
                continue;
            }

            if (value == -1) {
                S.erase(S.begin());
            } else {
                S.erase(prev(S.end()));
            }
        }

        if (S.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *S.rbegin() << ' ' << *S.begin() << '\n';
        }
    }
}
