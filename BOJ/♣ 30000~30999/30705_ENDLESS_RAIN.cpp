#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int parent[500001];
int color_count[1000001];

int get_parent(int child) {
    if (parent[child] == child) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) {
        return;
    }

    parent[a] = b;
}

void paint(int start, int end, int color) {
    int index = start;

    while (true) {
        index = get_parent(index);

        if (index >= end) {
            break;
        }

        color_count[color] += 1;
        merge(index, index + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= Q; i++) {
        int start, end;
        cin >> start >> end;

        paint(start, end, i);
    }

    int answer = 0;
    int saved = 0;

    for (int i = 1; i <= Q; i++) {
        saved += 1;

        answer += max(0, color_count[i] - saved);
        saved = max(0, saved - color_count[i]);
    }

    cout << answer;
}
