#include <algorithm>
#include <iostream>
#define INF 100'000'000'000
typedef long long ll;
using namespace std;

ll A[150002];
ll B[150002];
int N;

ll get_digit_sum(ll target, ll digit_len) {
    ll min_required_sum = 1;
    ll max_required_sum = 1;

    for (int i = 1; i < digit_len; i++) {
        min_required_sum *= 10;
    }

    for (int i = 1; i <= digit_len; i++) {
        max_required_sum *= 10;
    }

    max_required_sum -= 1;

    int range_start, range_end;

    int start = 0;
    int end = N + 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (target + B[mid] >= min_required_sum) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    range_start = start;

    start = 0;
    end = N + 1;

    while (start <= end) {
        mid = (start + end) / 2;

        if (target + B[mid] <= max_required_sum) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    range_end = end;

    return (range_end - range_start + 1) * digit_len;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    sort(B + 1, B + N + 1);
    B[0] = -INF;
    B[N + 1] = INF;

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 10; j++) {
            answer += get_digit_sum(A[i], j);
        }
    }

    cout << answer;
}
