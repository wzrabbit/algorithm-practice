#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int order[999];
int priority[1001];
vector<pair<int, int>> result;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 2; i++) {
        cin >> order[i];
        priority[order[i]] += 1;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        if (priority[i] == 0) {
            pq.push(i);
        }
    }

    for (int i = 1; i <= N - 2; i++) {
        int cur = pq.top();
        pq.pop();

        result.push_back({min(order[i], cur), max(order[i], cur)});

        priority[order[i]] -= 1;

        if (priority[order[i]] == 0) {
            pq.push(order[i]);
        }
    }

    int first = pq.top();
    pq.pop();
    int second = pq.top();
    result.push_back({first, second});

    sort(result.begin(), result.end());

    for (int i = 0; i < N - 1; i++) {
        cout << result[i].first << ' ' << result[i].second << '\n';
    }
}
