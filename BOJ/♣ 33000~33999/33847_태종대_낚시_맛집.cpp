#include <algorithm>
#include <iostream>
using namespace std;

struct Fish {
    int x, s, w;
};

bool operator<(const Fish &a, const Fish &b) { return a.s > b.s; }

Fish fishes[101];
int N, C;

int simulate_by_baits(int bait) {
    int profit = -bait * C;
    int index = 1;

    for (int i = 1; i <= N; i++) {
        if (bait >= fishes[i].x) {
            bait -= fishes[i].x;
            profit += fishes[i].w;
        }
    }

    return profit;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> C;

    for (int i = 1; i <= N; i++) {
        cin >> fishes[i].x >> fishes[i].s >> fishes[i].w;
    }

    sort(fishes + 1, fishes + N + 1);

    int answer = 0;

    for (int i = 1; i <= 10000; i++) {
        answer = max(answer, simulate_by_baits(i));
    }

    cout << answer;
}
