#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    ll odd_sum = 0;
    ll even_sum = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (i % 2 == 1) {
            odd_sum += cur;
        } else {
            even_sum += cur;
        }
    }

    if (N == 3 && odd_sum > even_sum) {
        cout << -1;
        return 0;
    }

    cout << abs(odd_sum - even_sum);
}