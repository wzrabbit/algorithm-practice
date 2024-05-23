#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Height {
    int n, h;
};

bool operator<(const Height &a, const Height &b) {
    return a.h < b.h;
}

vector<Height> heights;
bool has_water[1000002];
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        heights.push_back({i, cur});
    }

    sort(heights.begin(), heights.end());

    int max_land_count = 1;
    int land_count = 1;

    has_water[0] = true;
    has_water[N + 1] = true;

    for (int i = 0; i < N; i++) {
        Height cur = heights[i];

        has_water[cur.n] = true;
        land_count += 1;

        if (has_water[cur.n - 1]) {
            land_count -= 1;
        }

        if (has_water[cur.n + 1]) {
            land_count -= 1;
        }

        if (i == N - 1 || cur.h != heights[i + 1].h) {
            max_land_count = max(max_land_count, land_count);
        }
    }

    cout << max_land_count;
}
