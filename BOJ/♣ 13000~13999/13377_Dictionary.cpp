#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string test_string = "abcdefghi";
    map<string, int> order;
    int id = 0;

    do {
        order[test_string] = ++id;
    } while (next_permutation(test_string.begin(), test_string.end()));

    int T;
    cin >> T;

    while (T--) {
        string cur;
        cin >> cur;

        cout << order[cur] << '\n';
    }
}