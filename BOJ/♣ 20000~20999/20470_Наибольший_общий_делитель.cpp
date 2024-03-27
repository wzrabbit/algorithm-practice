#include <iostream>
#include <vector>
using namespace std;

int get_gcd(int x, int y) {
    if (x % y == 0) {
        return x % y;
    }

    return get_gcd(y, x % y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, D;
    cin >> N >> D;

    vector<int> answer;
    int gcd = -1;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (cur % D == 0) {
            if (gcd == -1) {
                gcd = cur;
            } else {
                gcd = get_gcd(gcd, cur);
            }

            answer.push_back(cur);
        }
    }

    if (gcd == D) {
        cout << answer.size() << '\n';

        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
    } else {
        cout << -1;
    }
}