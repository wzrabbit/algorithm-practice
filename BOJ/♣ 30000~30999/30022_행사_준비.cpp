#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

struct Price {
    ll a, b;
};

bool operator<(const Price &x, const Price &y) {
    return x.a - x.b < y.a - y.b;
}

Price prices[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, A, B;

    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++) {
        cin >> prices[i].a >> prices[i].b;
    }

    sort(prices + 1, prices + N + 1);

    ll result = 0;

    for (int i = 1; i <= A; i++) {
        result += prices[i].a;
    }

    for (int i = A + 1; i <= A + B; i++) {
        result += prices[i].b;
    }

    cout << result;
}
