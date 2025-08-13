#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> keys;
int W, L, N;

string generate_key(const vector<int> &up, const vector<int> &down) {
    string key_string = "";

    for (int i = 0; i < L; i++) {
        key_string += to_string(W - up[i] - down[i]);
        key_string += '.';
    }

    for (int i = 0; i < L - 1; i++) {
        key_string += to_string(up[i] - up[i + 1]);
        key_string += '.';
    }

    return key_string;
}

bool check_key_exist(const string &key) { return keys.find(key) != keys.end(); }

void add_key() {
    vector<int> up(L);
    vector<int> down(L);

    for (int i = 0; i < L; i++) {
        cin >> up[i];
    }

    for (int i = 0; i < L; i++) {
        cin >> down[i];
    }

    bool is_key_exist = false;

    string key = generate_key(up, down);
    is_key_exist |= check_key_exist(key);

    swap(up, down);

    key = generate_key(up, down);
    is_key_exist |= check_key_exist(key);

    reverse(up.begin(), up.end());
    reverse(down.begin(), down.end());

    key = generate_key(up, down);
    is_key_exist |= check_key_exist(key);

    swap(up, down);

    key = generate_key(up, down);
    is_key_exist |= check_key_exist(key);

    if (!is_key_exist) {
        keys.insert(key);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> W >> L >> N;

    for (int i = 1; i <= N; i++) {
        add_key();
    }

    cout << keys.size();
}
