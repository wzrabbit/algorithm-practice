#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    vector<ll> vec;

    while (Q--) {
        int command;
        cin >> command;

        if (command == 1) {
            int value;
            cin >> value;

            vec.push_back(value);
            continue;
        }

        vector<ll> new_vec;
        ll left_sum = 0;
        ll right_sum = 0;

        for (size_t i = 0; i < vec.size() / 2; i++) {
            left_sum += vec[i];
        }

        for (size_t i = vec.size() / 2; i < vec.size(); i++) {
            right_sum += vec[i];
        }

        if (left_sum > right_sum) {
            cout << right_sum << '\n';
            for (size_t i = 0; i < vec.size() / 2; i++) {
                new_vec.push_back(vec[i]);
            }
        } else {
            cout << left_sum << '\n';
            for (size_t i = vec.size() / 2; i < vec.size(); i++) {
                new_vec.push_back(vec[i]);
            }
        }

        swap(vec, new_vec);
    }

    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
}
