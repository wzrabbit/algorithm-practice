#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int parent[100000];

int get_parent(int child) {
    if (parent[child] == -1) return child;
    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) parent[a] = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, Q;
    cin >> V >> Q;

    string milk;
    cin >> milk;

    fill(parent, parent + V, -1);

    for (int i = 0; i < V - 1; i++) {
        int s, e;
        cin >> s >> e;
        s -= 1;
        e -= 1;

        if (milk[s] == milk[e]) {
            merge(s, e);
        }
    }

    while (Q--) {
        int s, e;
        char m;

        cin >> s >> e >> m;

        s -= 1;
        e -= 1;

        if (milk[get_parent(s)] == m || get_parent(s) != get_parent(e)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
}