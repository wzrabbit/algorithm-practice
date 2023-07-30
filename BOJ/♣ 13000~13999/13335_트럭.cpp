#include <iostream>
#include <queue>
using namespace std;

int trucks[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, W, L;
    cin >> N >> W >> L;

    for (int i = 1; i <= N; i++) {
        cin >> trucks[i];
    }

    int current_weight = 0;
    int crossed = 0;
    int put_index = 1;
    int time = 0;
    queue<int> bridge;

    for (int i = 1; i <= W; i++) {
        bridge.push(0);
    }

    while (crossed < N) {
        int current_crossed = bridge.front();
        bridge.pop();

        if (current_crossed != 0) {
            crossed += 1;
            current_weight -= current_crossed;
        }

        if (put_index <= N && current_weight + trucks[put_index] <= L) {
            bridge.push(trucks[put_index]);
            current_weight += trucks[put_index];
            put_index += 1;
        } else {
            bridge.push(0);
        }

        time += 1;
    }

    cout << time;
}