#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll raw[500001];
ll tree[2000001];

ll make_seg_tree(int start, int end, int index) {
    if (start == end) {
        return tree[index] = raw[start];
    }

    int mid = (start + end) / 2;

    return tree[index] = make_seg_tree(start, mid, index * 2) +
                         make_seg_tree(mid + 1, end, index * 2 + 1);
}

ll get_sum(int start, int end, int index, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && right >= end) {
        return tree[index];
    }

    int mid = (start + end) / 2;

    return get_sum(start, mid, index * 2, left, right) +
           get_sum(mid + 1, end, index * 2 + 1, left, right);
}

void update(int start, int end, int index, int target, ll plus) {
    if (target > end || target < start) {
        return;
    }

    tree[index] += plus;

    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, index * 2, target, plus);
        update(mid + 1, end, index * 2 + 1, target, plus);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> raw[i];
    }

    make_seg_tree(1, N, 1);

    for (int i = 1; i <= M; i++) {
        int cur;
        cin >> cur;

        update(1, N, 1, cur, -raw[cur]);
        cout << get_sum(1, N, 1, 1, cur - 1) + 1 << ' ';
    }
}
