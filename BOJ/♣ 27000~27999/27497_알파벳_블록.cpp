#include <deque>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    deque<char> dq;
    stack<int> history;

    for (int i = 1; i <= N; i++) {
        int command;
        cin >> command;

        if (command == 1) {
            char item;
            cin >> item;

            dq.push_back(item);
            history.push(1);
        } else if (command == 2) {
            char item;
            cin >> item;

            dq.push_front(item);
            history.push(2);
        } else {
            if (history.empty()) {
                continue;
            }

            int previous = history.top();
            history.pop();

            if (previous == 1) {
                dq.pop_back();
            } else {
                dq.pop_front();
            }
        }
    }

    if (dq.empty()) {
        cout << 0;
        return 0;
    }

    while (!dq.empty()) {
        char popped = dq.front();
        cout << popped;

        dq.pop_front();
    }
}