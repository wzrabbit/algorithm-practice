#include <iostream>
typedef long long ll;
using namespace std;

int arr[250001];

int get_required_mul_count(int before, int after) {
    int mul_count = 0;

    while (before > after) {
        after *= 2;
        mul_count += 1;
    }

    while (before * 2 <= after) {
        before *= 2;
        mul_count -= 1;
    }

    return mul_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll answer = 0;
    int prev_mul_count = 0;

    for (int i = 2; i <= N; i++) {
        int required_mul_count = get_required_mul_count(arr[i - 1], arr[i]);

        int cur_mul_count = max(0, prev_mul_count + required_mul_count);
        answer += cur_mul_count;
        prev_mul_count = cur_mul_count;
    }

    cout << answer;
}
