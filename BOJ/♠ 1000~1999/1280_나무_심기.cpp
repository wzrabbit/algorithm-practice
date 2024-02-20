#include <algorithm>
#include <iostream>
#define MAX 200'000
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

struct TreeInfo {
    ll c, s;
};

TreeInfo seg_tree[800005];

void add_tree(int start, int end, int index, int tree_position) {
    if (tree_position < start || tree_position > end) {
        return;
    }

    seg_tree[index].c += 1;
    seg_tree[index].s += tree_position;

    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;

    add_tree(start, mid, index * 2 + 1, tree_position);
    add_tree(mid + 1, end, index * 2 + 2, tree_position);
}

TreeInfo get_tree_info_by_range(int start, int end, int index, int left, int right) {
    if (end < left || right < start) {
        return {0, 0};
    }

    if (left <= start && end <= right) {
        return seg_tree[index];
    }

    int mid = (start + end) / 2;

    TreeInfo left_info = get_tree_info_by_range(start, mid, index * 2 + 1, left, right);
    TreeInfo right_info = get_tree_info_by_range(mid + 1, end, index * 2 + 2, left, right);

    return {left_info.c + right_info.c, left_info.s + right_info.s};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    ll answer = 1;

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        add_tree(0, MAX, 0, cur);

        if (i == 1) {
            continue;
        }

        TreeInfo left_info = {0, 0};
        TreeInfo right_info = {0, 0};

        if (cur != 0) {
            left_info = get_tree_info_by_range(0, MAX, 0, 0, cur - 1);
        }

        if (cur != MAX) {
            right_info = get_tree_info_by_range(0, MAX, 0, cur + 1, MAX);
        }

        ll left_dist_sum = cur * left_info.c - left_info.s;
        ll right_dist_sum = right_info.s - cur * right_info.c;

        answer = answer * ((left_dist_sum + right_dist_sum) % MOD) % MOD;
    }

    cout << answer;
}
