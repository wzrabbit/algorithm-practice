#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll bottle[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    ll X;
    cin >> N >> X;

    for (int i = 0; i < N; i++)
        cin >> bottle[i];
    sort(&bottle[0], &bottle[N]);

    int l = 0;
    int r = N - 1;
    int left_bottle = 0;
    int full_bottle = 0;

    while (l <= r) {
        if (bottle[r] == X) {
            full_bottle++;
            r--;
        } else if (l == r) {
            left_bottle++;
            break;
        } else if ((bottle[l] + bottle[r]) * 2 >= X) {
            full_bottle++;
            l++;
            r--;
        } else {
            left_bottle++;
            l++;
        }
    }

    full_bottle += left_bottle / 3;
    cout << full_bottle;
}