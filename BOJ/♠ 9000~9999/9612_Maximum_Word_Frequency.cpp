#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

string words[1001];
map<string, int> frequency;

bool custom_sort(string &s1, string &s2) {
    if (frequency[s1] != frequency[s2]) {
        return frequency[s1] > frequency[s2];
    }

    return s1 > s2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> words[i];

        if (frequency.count(words[i]) == 0) {
            frequency[words[i]] = 1;
        } else {
            frequency[words[i]] += 1;
        }
    }

    sort(words + 1, words + N + 1, custom_sort);

    cout << words[1] << ' ' << frequency[words[1]];
}