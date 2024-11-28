#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N <= 4) {
        cout << (N + 1) / 2;
        return 0;
    }

    int answer = 3;
    priority_queue<int> pq;

    int start = 2;

    while (true) {
        if (start * 2 + 3 <= N) {
            start *= 2;
        } else {
            break;
        }
    }

    start += 1;

    pq.push(start - 2);
    pq.push(N - start - 1);

    while (!pq.empty() && pq.top() >= 3) {
        int cur = pq.top();
        pq.pop();
        answer += 1;

        int div = cur / 2;
        int div2 = (cur - 1) / 2;

        if (div >= 3) {
            pq.push(div);
        }

        if (div2 >= 3) {
            pq.push(div2);
        }
    }

    cout << answer;
}
