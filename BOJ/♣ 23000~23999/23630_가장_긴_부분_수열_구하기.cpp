#include <algorithm>
#include <iostream>
using namespace std;

int arr[1000000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    int max_ = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < 20; i++) {
        int num = 1 << i;
        int cnt = 0;

        for (int j = 0; j < N; j++) {
            if ((arr[j] & num) > 0)
                cnt++;
        }

        max_ = max(max_, cnt);
    }

    cout << max_;
}