#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct City {
    int i, a;
};

bool operator<(const City &a, const City &b) { return a.a < b.a; }

City city[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        city[i].i = i;
        cin >> city[i].a;
    }

    sort(city + 1, city + N + 1);

    int limit = 0;
    bool is_left = true;

    vector<int> left, right;

    for (int i = 1; i <= N; i++) {
        if (city[i].a > limit) {
            cout << -1;
            return 0;
        }

        if (is_left) {
            is_left = false;
            left.push_back(city[i].i);
        } else {
            is_left = true;
            limit += 1;
            right.push_back(city[i].i);
        }
    }

    for (int i = 0; i < int(left.size()) - 1; i++) {
        cout << left[i] << ' ' << left[i + 1] << '\n';
    }

    for (int i = 0; i < int(right.size()) - 1; i++) {
        cout << right[i] << ' ' << right[i + 1] << '\n';
    }

    cout << left.back() << ' ' << right.back();
}
