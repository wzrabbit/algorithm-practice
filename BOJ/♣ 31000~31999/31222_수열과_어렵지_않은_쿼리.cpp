#include <iostream>
using namespace std;

struct Value {
    int s, e, a;
};

int arr[200001];
Value seg_tree[800001];

Value make_seg_tree(int start, int end, int index) {
    if (start == end) {
        return seg_tree[index] = {arr[start], arr[end], 1};
    }

    int mid = (start + end) / 2;
    Value left_value = make_seg_tree(start, mid, index * 2);
    Value right_value = make_seg_tree(mid + 1, end, index * 2 + 1);

    int seg_answer = left_value.a + right_value.a;

    if (left_value.e == right_value.s) {
        seg_answer -= 1;
    }

    return seg_tree[index] = {left_value.s, right_value.e, seg_answer};
}

Value update_value(int start, int end, int index, int target, int value) {
    if (target < start || end < target) {
        return seg_tree[index];
    }

    if (start == end) {
        return seg_tree[index] = {value, value, 1};
    }

    int mid = (start + end) / 2;
    Value left_value = update_value(start, mid, index * 2, target, value);
    Value right_value = update_value(mid + 1, end, index * 2 + 1, target, value);

    int seg_answer = left_value.a + right_value.a;

    if (left_value.e == right_value.s) {
        seg_answer -= 1;
    }

    return seg_tree[index] = {left_value.s, right_value.e, seg_answer};
}

Value get_answer(int start, int end, int index, int left, int right) {
    if (end < left || right < start) {
        return {-1, -1, -1};
    }

    if (left <= start && end <= right) {
        return seg_tree[index];
    }

    int mid = (start + end) / 2;
    Value left_value = get_answer(start, mid, index * 2, left, right);
    Value right_value = get_answer(mid + 1, end, index * 2 + 1, left, right);

    if (left_value.s == -1) {
        return right_value;
    }

    if (right_value.s == -1) {
        return left_value;
    }

    int seg_answer = left_value.a + right_value.a;

    if (left_value.e == right_value.s) {
        seg_answer -= 1;
    }

    return {left_value.s, right_value.e, seg_answer};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    make_seg_tree(1, N, 1);

    while (Q--) {
        int q, a, b;
        cin >> q >> a >> b;

        if (q == 1) {
            update_value(1, N, 1, a, b);
            continue;
        }

        cout << get_answer(1, N, 1, a, b).a << '\n';
    }
}
