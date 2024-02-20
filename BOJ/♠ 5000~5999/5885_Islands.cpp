#include <algorithm>
#include <iostream>
using namespace std;

struct Land {
    int i, h;
};

bool operator<(const Land &a, const Land &b) {
    return a.h < b.h;
}

Land lands[100002];
bool is_water[100002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        lands[i].i = i;
        cin >> lands[i].h;
    }

    sort(lands + 1, lands + N + 1);

    int cur_land_count = 1;
    int max_land_count = 1;
    is_water[0] = true;
    is_water[N + 1] = true;

    for (int i = 1; i <= N; i++) {
        int pos = lands[i].i;
        is_water[pos] = true;

        if (!is_water[pos - 1] && !is_water[pos + 1]) {
            cur_land_count += 1;
        }

        if (is_water[pos - 1] && is_water[pos + 1]) {
            cur_land_count -= 1;
        }

        if (lands[i].h != lands[i + 1].h) {
            max_land_count = max(cur_land_count, max_land_count);
        }
    }

    cout << max_land_count;
}
