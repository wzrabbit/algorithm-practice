#include <iostream>
using namespace std;

int holes[100001];
int answer[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> holes[i];
    }

    int cur_size = 1;

    for (int i = 1; i <= N; i++) {
        while (cur_size <= N && holes[i] + i - 1 >= cur_size) {
            answer[cur_size] = i;
            cur_size += 1;
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int cur;
        cin >> cur;

        cout << answer[cur] << ' ';
    }
}
