#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    set<int> rocks;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        rocks.insert(cur);
    }

    cout << N - rocks.size();
}