#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int origin_count[26] = {};
int candidate_count[26] = {};
string origin, candidate;

bool is_correct() {
    int diff = 0;

    for (int i = 0; i < 26; i++) {
        diff += abs(origin_count[i] - candidate_count[i]);
    }

    if (diff == 2) {
        return true;
    }

    if (diff == 0 && origin.size() != candidate.size()) {
        return true;
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> origin >> Q;

    for (size_t i = 0; i < origin.size(); i++) {
        origin_count[origin[i] - 'a'] += 1;
    }

    while (Q--) {
        cin >> candidate;
        bool success = false;

        fill(candidate_count, candidate_count + 26, 0);

        if (candidate.size() < origin.size()) {
            cout << "NO\n";
            continue;
        }

        for (size_t i = 0; i < origin.size(); i++) {
            candidate_count[candidate[i] - 'a'] += 1;
        }

        success |= is_correct();

        for (size_t i = origin.size(); i < candidate.size(); i++) {
            candidate_count[candidate[i - origin.size()] - 'a'] -= 1;
            candidate_count[candidate[i] - 'a'] += 1;
            success |= is_correct();
        }

        if (success) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}