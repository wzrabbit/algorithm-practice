#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct Glass {
    int i;
    int c;
};

int capacity[300001];
int amount[300001];
int parent[300001];
int next_glass[300001];
int N, Q;

int get_parent(int child) {
    if (parent[child] == child) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        parent[a] = b;
    }
}

void make_next_glass() {
    stack<Glass> S;

    for (int i = 1; i <= N; i++) {
        while (!S.empty() && S.top().c < capacity[i]) {
            next_glass[S.top().i] = i;
            S.pop();
        }

        S.push({i, capacity[i]});
    }
}

void pour(int target, int value) {
    int left = value;

    while (left > 0) {
        target = get_parent(target);

        if (target == 0) {
            break;
        }

        int matched = min(capacity[target] - amount[target], left);
        amount[target] += matched;
        left -= matched;

        if (capacity[target] - amount[target] == 0) {
            merge(target, next_glass[target]);
        }
    }
}

int get_amount(int target) { return amount[target]; }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> capacity[i];
        parent[i] = i;
    }

    make_next_glass();

    while (Q--) {
        char query;
        cin >> query;

        if (query == '?') {
            int target;
            cin >> target;
            cout << get_amount(target) << '\n';
            continue;
        }

        int target, value;
        cin >> target >> value;
        pour(target, value);
    }
}
