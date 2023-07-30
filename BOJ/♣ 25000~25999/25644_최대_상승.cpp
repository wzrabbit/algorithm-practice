#include <algorithm>
#include <iostream>
#define INF 1'000'000'001
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int best = 0;
    int min_value = INF;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        min_value = min(min_value, cur);
        best = max(best, cur - min_value);
    }

    cout << best;
}