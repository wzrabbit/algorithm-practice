#include <iostream>
using namespace std;

// 맵, 셋 안쓰고 뚫기 가능??

int arr[20000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        arr[cur + 10000000] += 1;
    }

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int cur;
        cin >> cur;

        cout << arr[cur + 10000000] << ' ';
    }
}