#include <iostream>
typedef long long ll;
using namespace std;

ll arr[1000000];
bool change[60];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        ll num = 1;
        for (int j = 0; j <= 60; j++) {
            if ((arr[i] & num) == 0) {
                change[j] = true;
                break;
            }
            num <<= 1;
        }
    }

    ll best = 0;
    ll cur = arr[0];
    ll num = 1;
    for (int i = 1; i < N; i++) {
        cur ^= arr[i];
    }

    for (int i = 0; i <= 10; i++) {
        cout << change[i] << ' ';
    }
    cout << '\n';

    for (int i = 0; i < 60; i++) {
        cur ^= num;
        if (change[i] && cur > best) {
            best = cur;
        }
        num <<= 1;
    }

    cout << best;
}