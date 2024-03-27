#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int N, Q;
ll prefix[525000][40];

void update_upper(ll target, ll power, ll dist) {
    if (target == 1) {
        return;
    }

    while (target >= 2 && dist >= 1) {
        bool is_left = target % 2 == 0;

        target /= 2;
        prefix[target][0] += power;

        if (dist - 2 >= 0) {
            ll child = is_left ? target * 2 + 1 : target * 2;
            prefix[child][dist - 2] += power;
        }

        dist -= 1;
    }
}

void update_lower(ll target, ll power, ll dist) {
    prefix[target][dist] += power;
}

void apply_prefix() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < 40; j++) {
            prefix[i * 2][j - 1] += prefix[i][j];
            prefix[i * 2 + 1][j - 1] += prefix[i][j];
        }
    }
}

void print_answer() {
    for (int i = 1; i <= N; i++) {
        ll sum = 0;

        for (int j = 0; j < 40; j++) {
            sum += prefix[i][j];
        }

        cout << sum << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    while (Q--) {
        ll target, power, dist;
        cin >> target >> power >> dist;

        update_upper(target, power, dist);
        update_lower(target, power, dist);
    }

    apply_prefix();
    print_answer();
}
