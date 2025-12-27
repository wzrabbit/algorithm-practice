#include <iostream>
using namespace std;

int cnt[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N * 2; i++) {
        int cur;
        cin >> cur;
        cnt[cur] += 1;

        if (cnt[cur] >= 3) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}
