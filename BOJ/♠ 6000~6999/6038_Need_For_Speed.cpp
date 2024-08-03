#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Part {
    ll f, m, i;
};

bool operator<(const Part& a, const Part& b) {
    return a.f * b.m > b.f * a.m;
}

Part parts[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll F, M, N;
    cin >> F >> M >> N;

    for (int i = 1; i <= N; i++) {
        cin >> parts[i].f >> parts[i].m;
        parts[i].i = i;
    }

    sort(parts + 1, parts + N + 1);
    vector<ll> answer;

    for (int i = 1; i <= N; i++) {
        ll next_force = F + parts[i].f;
        ll next_mass = M + parts[i].m;

        if (next_force * M > F * next_mass) {
            answer.push_back(parts[i].i);
            F += parts[i].f;
            M += parts[i].m;
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0) {
        cout << "NONE";
        return 0;
    }

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}
