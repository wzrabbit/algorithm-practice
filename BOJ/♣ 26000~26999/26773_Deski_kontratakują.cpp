#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int woods[1000000];
int N;

ll is_possible(int width) {
    ll height = 0;

    for (int i = 0; i < N; i++) {
        height += woods[i] / width;
    }

    if (height >= 4) {
        return true;
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> woods[i];
    }

    ll start = 1;
    ll end = 1000000000;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (is_possible(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << end * end;
}