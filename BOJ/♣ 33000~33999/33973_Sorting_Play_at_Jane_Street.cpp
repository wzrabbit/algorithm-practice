#include <algorithm>
#include <iostream>
#include <vector>
#define MOD 998'244'353
typedef long long ll;
using namespace std;

vector<int> arrays[2001];
vector<int> stables;
int unstable;
ll factorial[2001];

bool compare(const vector<int> &a, const vector<int> &b) {
    for (size_t i = 0; i < stables.size(); i++) {
        if (a[stables[i] - 1] != b[stables[i] - 1]) {
            return a[stables[i] - 1] < b[stables[i] - 1];
        }
    }

    if (a[unstable - 1] != b[unstable - 1]) {
        return a[unstable - 1] < b[unstable - 1];
    }

    return false;
}

bool has_exact_priority(const vector<int> &a, const vector<int> &b) {
    for (size_t i = 0; i < stables.size(); i++) {
        if (a[stables[i] - 1] != b[stables[i] - 1]) {
            return false;
        }
    }

    if (a[unstable - 1] != b[unstable - 1]) {
        return false;
    }

    return true;
}

void make_factorial() {
    factorial[0] = 1;

    for (int i = 1; i <= 2000; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cur;
            cin >> cur;

            arrays[i].push_back(cur);
        }
    }

    while (Q--) {
        int mode, index;
        cin >> mode >> index;

        if (mode == 1) {
            stables.clear();
            unstable = index;
            continue;
        }

        stables.push_back(index);
    }

    reverse(stables.begin(), stables.end());

    sort(arrays + 1, arrays + N + 1, compare);

    make_factorial();

    int combo = 1;
    ll answer = 1;

    for (int i = 1; i <= N - 1; i++) {
        if (has_exact_priority(arrays[i], arrays[i + 1])) {
            combo += 1;
        } else {
            answer = answer * factorial[combo] % MOD;
            combo = 1;
        }
    }

    answer = answer * factorial[combo] % MOD;

    cout << answer;
}
