#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

struct Fan {
    int g, p;
};

bool operator<(const Fan& a, const Fan& b) {
    return a.p < b.p;
}

int first_index[2000001];
Fan arr[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    assert(N != 1);

    fill(first_index, first_index + 2000001, -1);
    first_index[1000000] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].g >> arr[i].p;
    }

    sort(arr + 1, arr + N + 1);

    int prefix = 1000000;
    int answer = 0;

    for (int i = 1; i <= N; i++) {
        prefix += (arr[i].g == 0) ? 1 : -1;

        if (first_index[prefix] != -1) {
            answer = max(answer, arr[i].p - arr[first_index[prefix] + 1].p);
        }

        if (first_index[prefix] == -1) {
            first_index[prefix] = i;
        }
    }

    cout << answer;
}
