#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    set<int> S;

    for (int i = 1; i <= N; i++) {
        int _, cur;
        cin >> _ >> cur;
        S.insert(cur);
    }

    cout << S.size();
}
