#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> values[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, D;
    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;

        values[i % D].push_back(cur);
    }

    for (int i = 0; i < D; i++) {
        sort(values[i].begin(), values[i].end());
    }

    int prev = -1;

    for (int i = 0; i < N; i++) {
        int cur = values[i % D][i / D];

        if (prev > cur) {
            cout << "No";
            return 0;
        }

        prev = cur;
    }

    cout << "Yes";
}
