#include <iostream>
#include <set>
using namespace std;

int arr[10001];
set<int> prefix;

bool check(int sum, int N) {
    int cur_sum = 0;
    bool closed = true;

    for (int i = 1; i <= N; i++) {
        closed = false;
        cur_sum += arr[i];
        if (cur_sum == sum) {
            cur_sum = 0;
            closed = true;
        }
    }

    if (closed)
        return true;
    else
        return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        int x = 0;
        int total_sum = 0;

        for (int i = 1; i <= N; i++) {
            total_sum += arr[i];
        }

        for (int i = 1; i <= N; i++) {
            x += arr[i];
            if (check(x, N)) {
                cout << x << '\n';
                break;
            }
        }
    }
}