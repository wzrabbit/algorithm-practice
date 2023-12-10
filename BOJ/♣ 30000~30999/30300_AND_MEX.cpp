#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int get_mex(vector<int> &elements, int candidate) {
    set<int> and_numbers;

    for (size_t i = 0; i < elements.size(); i++) {
        and_numbers.insert(elements[i] & candidate);
    }

    int cur = 0;

    while (true) {
        if (and_numbers.find(cur) == and_numbers.end()) {
            return cur;
        }

        cur += 1;
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> elements;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            elements.push_back(cur);
        }

        int best_mex = 1;
        int best_candidate = 0;

        for (int i = 1; i <= 30; i++) {
            int cur_mex = get_mex(elements, (1 << i) - 1);

            if (cur_mex > best_mex) {
                best_mex = cur_mex;
                best_candidate = (1 << i) - 1;
            }
        }

        cout << best_candidate << '\n';
    }
}
