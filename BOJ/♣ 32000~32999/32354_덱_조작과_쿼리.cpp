#include <iostream>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

int parent[500001];
ll value[500001];
int previous[500001];

int get_parent(int child) {
    if (parent[child] == -1) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    fill(parent, parent + Q + 1, -1);

    for (int i = 1; i <= Q; i++) {
        string q;
        cin >> q;

        if (q == "push") {
            ll cur;
            cin >> cur;

            int target = get_parent(i - 1);
            previous[i] = target;
            value[i] = value[target] + cur;
        }

        if (q == "pop") {
            int target = previous[get_parent(i - 1)];
            merge(target, i);
        }

        if (q == "restore") {
            ll cur;
            cin >> cur;

            merge(cur, i);
        }

        if (q == "print") {
            merge(i - 1, i);
            cout << value[get_parent(i)] << '\n';
        }
    }
}
