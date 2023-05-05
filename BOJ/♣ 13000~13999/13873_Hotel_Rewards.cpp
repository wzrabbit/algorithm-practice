#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<>> free_hotels;
    int total_price = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        total_price += cur;

        if (i % (K + 1) == 0) {
            free_hotels.push(cur);
            continue;
        }

        if (!free_hotels.empty() && cur > free_hotels.top()) {
            free_hotels.pop();
            free_hotels.push(cur);
        }
    }

    while (!free_hotels.empty()) {
        total_price -= free_hotels.top();
        free_hotels.pop();
    }

    cout << total_price;
}