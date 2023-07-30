#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> answer;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    ll cur = 2;
    cin >> N;

    while (N > 1 && cur <= 1000000) {
        while (N % cur == 0) {
            N /= cur;
            answer.push_back(cur);
        }

        cur += 1;
    }

    if (N > 1) {
        answer.push_back(N);
    }

    cout << answer.size() << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}