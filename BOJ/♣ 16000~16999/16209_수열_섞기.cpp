#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> pluses;
vector<int> minuses;
int zero_count = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (cur > 0) {
            pluses.push_back(cur);
        } else if (cur < 0) {
            minuses.push_back(cur);
        } else {
            zero_count += 1;
        }
    }

    sort(pluses.begin(), pluses.end());
    sort(minuses.begin(), minuses.end(), greater<int>());
    vector<int> storage;

    for (size_t i = 1; i < pluses.size(); i += 2) {
        cout << pluses[i] << ' ';
    }

    for (size_t i = 0; i < pluses.size(); i += 2) {
        storage.push_back(pluses[i]);
    }

    for (int i = (int)storage.size() - 1; i >= 0; i--) {
        cout << storage[i] << ' ';
    }

    for (int i = 1; i <= zero_count; i++) {
        cout << 0 << ' ';
    }

    storage.clear();

    for (size_t i = 0; i < minuses.size(); i += 2) {
        cout << minuses[i] << ' ';
    }

    for (size_t i = 1; i < minuses.size(); i += 2) {
        storage.push_back(minuses[i]);
    }

    for (int i = (int)storage.size() - 1; i >= 0; i--) {
        cout << storage[i] << ' ';
    }
}