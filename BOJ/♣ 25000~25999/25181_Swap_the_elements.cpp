#include <algorithm>
#include <iostream>
using namespace std;

struct Clone {
    int i, n;
};

bool operator<(const Clone &a, const Clone &b) {
    return a.n < b.n;
}

int element_count[100001];
int arr[5001];
Clone clones[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        clones[i] = {i, arr[i]};
        element_count[arr[i]] += 1;
    }

    for (int i = 1; i <= 100000; i++) {
        if (element_count[i] > N / 2) {
            cout << -1;
            return 0;
        }
    }

    sort(clones + 1, clones + N + 1);

    for (int i = 1; i <= N - N / 2; i++) {
        swap(arr[clones[i].i], arr[clones[i + N / 2].i]);
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}
