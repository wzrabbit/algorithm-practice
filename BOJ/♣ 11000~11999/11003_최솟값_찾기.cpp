#include <iostream>
#include <queue>
using namespace std;

struct Value {
    int i, v;
};

bool operator<(Value a, Value b) {
    return a.v > b.v;
}

Value arr[5000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, L;
    cin >> N >> L;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        arr[i] = {i, cur};
    }

    priority_queue<Value> pq;

    for (int i = 1; i <= N; i++) {
        pq.push(arr[i]);

        while (true) {
            Value top = pq.top();

            if (top.i > i - L) {
                break;
            }

            pq.pop();
        }

        cout << pq.top().v << ' ';
    }
}