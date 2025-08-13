#include <iostream>
#define INF 1'000'000'001
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll min_value = INF;
    ll answer = 0;

    int R, C;
    cin >> R >> C;

    for (int i = 1; i <= R * C; i++) {
        ll cur;
        cin >> cur;

        min_value = min(min_value, cur);
        answer += cur;
    }

    answer -= min_value;

    cout << answer;
}
