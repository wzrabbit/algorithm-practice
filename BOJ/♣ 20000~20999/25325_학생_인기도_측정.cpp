#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string pupils[101];
map<string, int> score;

bool custom_sort(string &s1, string &s2) {
    if (score[s1] != score[s2]) {
        return score[s1] > score[s2];
    }

    return s1 < s2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> pupils[i];
    }

    while (!cin.eof()) {
        string cur;
        cin >> cur;

        if (score.count(cur) == 0) {
            score[cur] = 1;
        } else {
            score[cur] += 1;
        }
    }

    sort(pupils + 1, pupils + N + 1, custom_sort);

    for (int i = 1; i <= N; i++) {
        cout << pupils[i] << ' ' << score[pupils[i]] << '\n';
    }
}