#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct st {
    int v, p;
};

bool operator<(st a, st b) {
    return a.v < b.v;
}

map<string, int> vote;
map<int, int> s_vote;
vector<string> babo;

bool check_babo(string name, int score) {
    vector<st> storage;
    for (auto it = s_vote.begin(); it != s_vote.end(); it++) {
        storage.push_back({it->first, it->second});

        if (score == it->first) {
            storage[storage.size() - 1].p--;

            if (storage[storage.size() - 1].p == 0) {
                storage.pop_back();
            }
        }
    }

    int cur = score;
    for (int i = 0; i < storage.size(); i++) {
        if (cur <= storage[i].v) {
            return false;
        } else {
            cur += storage[i].v * storage[i].p;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (!vote.count(s))
            vote[s] = 1;
        else
            vote[s]++;
    }

    for (auto it = vote.begin(); it != vote.end(); it++) {
        if (!s_vote.count(it->second))
            s_vote[it->second] = 1;
        else
            s_vote[it->second]++;
    }

    for (auto it = vote.begin(); it != vote.end(); it++) {
        if (!check_babo(it->first, it->second)) {
            babo.push_back(it->first);
        }
    }

    sort(babo.begin(), babo.end());

    cout << babo.size() << '\n';
    for (int i = 0; i < babo.size(); i++) {
        cout << babo[i] << '\n';
    }
}