#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int arr[50001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    priority_queue<int, vector<int>, greater<int>> pq;
    int penalty = 0;
    int index = 1;

    for (int i = 1; i <= M; i++) {
        pq.push(0);
    }

    while (!pq.empty()) {
        int popped = pq.top();
        pq.pop();
        penalty += popped;

        if (index <= N) {
            popped += arr[index++];
            pq.push(popped);
        }
    }

    cout << penalty;
}