#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        vector<int> element_count = {0, 0, 0, 0};
        vector<int> elements;

        int N;
        cin >> N;

        int total_xor = 0;

        for (int i = 0; i < N; i++) {
            int cur;
            cin >> cur;

            element_count[cur] += 1;
            total_xor ^= cur;
            elements.push_back(cur);
        }

        bool flag = false;

        for (int i = 0; i < N; i++) {
            if (elements[i] == 3) {
                break;
            }

            if (elements[i] != 0) {
                flag = true;
                break;
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            if (elements[i] == 3) {
                break;
            }

            if (elements[i] != 0) {
                flag = true;
                break;
            }
        }

        if (element_count[3] == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (total_xor != 3 || flag) {
            cout << 1 << '\n';
            continue;
        }

        if (element_count[3] != N) {
            cout << 2 << '\n';
            continue;
        }

        if (N > 1) {
            cout << 3 << '\n';
            continue;
        }

        cout << -1 << '\n';
    }
}
