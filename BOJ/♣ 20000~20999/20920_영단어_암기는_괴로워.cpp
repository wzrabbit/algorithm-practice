#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> word_count;
vector<string> words;

bool custom_sort(string &s1, string &s2) {
    if (word_count[s1] != word_count[s2]) {
        return word_count[s1] > word_count[s2];
    }

    if (s1.length() != s2.length()) {
        return s1.length() > s2.length();
    }

    return s1 < s2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string cur;
        cin >> cur;

        if (cur.length() < M) {
            continue;
        }

        if (word_count.count(cur) == 0) {
            word_count[cur] = 1;
            words.push_back(cur);
        } else {
            word_count[cur] += 1;
        }
    }

    sort(words.begin(), words.end(), custom_sort);

    for (size_t i = 0; i < words.size(); i++) {
        cout << words[i] << '\n';
    }
}