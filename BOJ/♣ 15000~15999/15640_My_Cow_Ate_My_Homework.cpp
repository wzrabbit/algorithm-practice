#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll arr[100001];
ll smallest[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    cin >> N;

    ll sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    smallest[N] = arr[N];

    for (int i = N - 1; i >= 1; i--) {
        smallest[i] = min(smallest[i + 1], arr[i]);
    }

    ll best = 0;
    vector<ll> answers;

    for (int i = 1; i <= N - 2; i++) {
        sum -= arr[i];
        ll cur = sum - smallest[i];
        cout << "CUR: " << cur << '\n';

        if (cur > best) {
            answers.clear();
            cout << "RESET: " << i << ' ' << cur << '\n';
        }

        if (cur >= best) {
            answers.push_back(i);
            cout << "ADD: " << i << ' ' << cur << '\n';
        }
    }

    cout << best << '\n';

    for (size_t i = 0; i < answers.size(); i++) {
        cout << answers[i] << ' ';
    }
}