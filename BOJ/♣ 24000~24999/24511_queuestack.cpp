#include <iostream>
#include <queue>
using namespace std;

int memory[100001];
bool is_stack[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> is_stack[i];
    }

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        memory[i] = cur;
    }

    queue<int> q;

    for (int i = N; i >= 1; i--) {
        if (!is_stack[i]) {
            q.push(memory[i]);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int cur;
        cin >> cur;

        q.push(cur);

        cout << q.front() << ' ';
        q.pop();
    }
}