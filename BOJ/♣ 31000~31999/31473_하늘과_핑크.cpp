#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll A[1001];
ll B[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    ll A_sum = 0;
    ll B_sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A_sum += A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        B_sum += B[i];
    }

    cout << B_sum << ' ' << A_sum;
}
