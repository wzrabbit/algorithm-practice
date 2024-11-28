#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int color = 1;
    int combo = 0;
    vec.push_back(0);

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (cur == color) {
            combo += 1;
            continue;
        }

        vec.push_back(combo);
        color = cur;
        combo = 1;
    }

    vec.push_back(combo);
    vec.push_back(0);

    int best = 0;

    for (size_t i = 0; i < vec.size() - 1; i++) {
        best = max(best, vec[i] + vec[i + 1]);
    }

    cout << best;
}
