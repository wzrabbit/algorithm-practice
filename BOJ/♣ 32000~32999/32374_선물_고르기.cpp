#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int gifts[200001];
multiset<int> boxes;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> gifts[i];
    }

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        boxes.insert(cur);
    }

    for (int i = 1; i <= K; i++) {
        int cur;
        cin >> cur;

        auto it = boxes.find(cur);
        boxes.erase(it);
    }

    int maximum_left_box = *boxes.rbegin();
    sort(gifts + 1, gifts + N + 1);

    int start = 1;
    int end = N;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (gifts[mid] <= maximum_left_box) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << gifts[end];
}
