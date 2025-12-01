#include <iostream>
using namespace std;

int arr[20001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        arr[cur] = i;
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << '\n';
    }
}
