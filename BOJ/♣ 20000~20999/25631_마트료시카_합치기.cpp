#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<int, int> doll_count;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int current;
        cin >> current;

        if (doll_count.find(current) == doll_count.end()) {
            doll_count[current] = 1;
        } else {
            doll_count[current] += 1;
        }
    }

    int max_doll_count = 0;

    for (auto it = doll_count.begin(); it != doll_count.end(); it++) {
        max_doll_count = max(max_doll_count, it->second);
    }

    cout << max_doll_count;
}