#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll prefix[200001];
int N, Q;

void make_prefixes() {
    sort(prefix + 1, prefix + N + 1, greater<ll>());
    for (int i = 1; i <= N; i++) {
        prefix[i] += prefix[i - 1];
    }
}

int get_task_count(ll goal) {
    int start = 1;
    int end = N;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (prefix[mid] >= goal) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return start;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> prefix[i];
    }

    make_prefixes();

    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        ll cur;
        cin >> cur;
        cout << get_task_count(cur) << '\n';
    }
}