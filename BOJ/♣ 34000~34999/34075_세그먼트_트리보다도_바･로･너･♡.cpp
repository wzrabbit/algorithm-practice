#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Algorithm {
    string s;
    int t;
};

Algorithm algorithms[230];
map<string, int> member_tier_map;
string current_member = "";
int N, M, Q;

bool is_more_preferred(const Algorithm &a, const Algorithm &b) {
    int member_tier = member_tier_map[current_member];
    int a_tier_gap = abs(member_tier - a.t);
    int b_tier_gap = abs(member_tier - b.t);

    if (a_tier_gap != b_tier_gap) {
        return a_tier_gap < b_tier_gap;
    }

    return a.s < b.s;
}

vector<string> get_preferred_algorithm_names() {
    Algorithm first = {"", 99};
    Algorithm second = {"", 99};

    for (int i = 1; i <= N; i++) {
        if (is_more_preferred(algorithms[i], first)) {
            second = first;
            first = algorithms[i];
            continue;
        }

        if (is_more_preferred(algorithms[i], second)) {
            second = algorithms[i];
        }
    }

    return vector<string>{first.s, second.s};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> algorithms[i].s >> algorithms[i].t;
    }

    cin >> M;

    for (int i = 1; i <= M; i++) {
        string name;
        int tier;
        cin >> name >> tier;
        member_tier_map[name] = tier;
    }

    cin >> Q;

    while (Q--) {
        string a, b, c;
        cin >> a >> b >> c;

        if (c == "chan!") {
            current_member = a;
            cout << "hai!\n";
            continue;
        }

        vector<string> preferred_algorithms = get_preferred_algorithm_names();
        cout << preferred_algorithms[1] << " yori mo "
             << preferred_algorithms[0] << '\n';
    }
}
