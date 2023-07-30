#include <iostream>
using namespace std;

bool has_num[2000001];
bool is_checked[2000004];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        has_num[cur] = true;
    }

    if (!has_num[0]) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= 2000000; i++) {
        if (!has_num[i]) continue;

        int cur = i;

        while (cur < 2000003) {
            if (has_num[cur / i]) {
                is_checked[cur] = true;
            }

            cur += i;
        }
    }

    for (int i = 1; i <= 2000003; i++) {
        if (!is_checked[i]) {
            cout << i;
            return 0;
        }
    }
}