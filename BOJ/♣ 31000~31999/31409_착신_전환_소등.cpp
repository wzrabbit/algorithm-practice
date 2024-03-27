#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int need = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        if (arr[i] == i) {
            need += 1;
        }
    }

    cout << need << '\n';

    for (int i = 1; i <= N; i++) {
        if (arr[i] == i) {
            cout << ((i == N) ? 1 : i + 1) << ' ';
        } else {
            cout << arr[i] << ' ';
        }
    }
}
