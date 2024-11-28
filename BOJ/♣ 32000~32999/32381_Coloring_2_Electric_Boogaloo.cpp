#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Instruction {
    char c;
    ll i;
};

Instruction instructions[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    ll R = 0;
    ll C = 0;
    ll prev = 0;
    bool success = true;

    for (int i = 1; i <= Q; i++) {
        ll cur;
        cin >> cur;

        ll diff = cur - prev;

        if (R != N && diff == N - C * 2) {
            R += 1;
            instructions[i] = {'R', R};
            prev = cur;
            continue;
        }

        if (R != 0 && diff == -(N - C * 2)) {
            instructions[i] = {'R', R};
            R -= 1;
            prev = cur;
            continue;
        }

        if (C != N && diff == N - R * 2) {
            C += 1;
            instructions[i] = {'C', C};
            prev = cur;
            continue;
        }

        if (C != 0 && diff == -(N - R * 2)) {
            instructions[i] = {'C', C};
            C -= 1;
            prev = cur;
            continue;
        }

        success = false;
        break;
    }

    if (success) {
        for (int i = 1; i <= Q; i++) {
            cout << instructions[i].c << ' ' << instructions[i].i << '\n';
        }
        return 0;
    }

    cout << -1;
}
