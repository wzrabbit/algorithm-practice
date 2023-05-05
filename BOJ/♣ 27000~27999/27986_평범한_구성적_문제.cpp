#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    int min_area = 9999;

    for (int i = 1; i <= M; i++) {
        int start, end;
        cin >> start >> end;
        min_area = min(min_area, end - start + 1);
    }

    for (int i = 0; i < N; i++) {
        cout << i % min_area + 1 << ' ';
    }
}