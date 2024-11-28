#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

struct Node {
    int n, l, r;
};

Node nodes[1000001];
string candy_string = "";
int N, R, Q;
int top_first_node;
int top_kth_node;
int top_last_node;
int bottom_first_node;
int bottom_kth_node;
int bottom_last_node;

void exchange() {
    swap(top_first_node, bottom_first_node);
    swap(top_kth_node, bottom_kth_node);
    swap(nodes[top_kth_node].r, nodes[bottom_kth_node].r);

    int next_top_node = nodes[top_kth_node].r;
    int next_bottom_node = nodes[bottom_kth_node].r;

    if (nodes[top_kth_node].r == -1) {
        swap(top_last_node, bottom_last_node);
    } else {
        swap(nodes[next_top_node].l, nodes[next_bottom_node].l);
    }
}

void shift_left(int belt_no) {
    if (N == 1) {
        return;
    }

    if (belt_no == 1) {
        int old_top_first_node = top_first_node;
        int old_top_last_node = top_last_node;

        top_first_node = nodes[old_top_first_node].r;
        top_last_node = old_top_first_node;

        nodes[top_last_node].l = old_top_last_node;
        nodes[old_top_last_node].r = top_last_node;
        nodes[top_last_node].r = -1;
        nodes[top_first_node].l = -1;

        top_kth_node = (top_kth_node == old_top_first_node) ? top_first_node : nodes[top_kth_node].r;

        return;
    }

    int old_bottom_first_node = bottom_first_node;
    int old_bottom_last_node = bottom_last_node;

    bottom_first_node = nodes[old_bottom_first_node].r;
    bottom_last_node = old_bottom_first_node;

    nodes[bottom_last_node].l = old_bottom_last_node;
    nodes[old_bottom_last_node].r = bottom_last_node;
    nodes[bottom_last_node].r = -1;
    nodes[bottom_first_node].l = -1;

    bottom_kth_node = (bottom_kth_node == old_bottom_first_node) ? bottom_first_node : nodes[bottom_kth_node].r;
}

void shift_right(int belt_no) {
    if (N == 1) {
        return;
    }

    if (belt_no == 1) {
        int old_top_first_node = top_first_node;
        int old_top_last_node = top_last_node;

        top_last_node = nodes[old_top_last_node].l;
        top_first_node = old_top_last_node;

        nodes[top_first_node].r = old_top_first_node;
        nodes[old_top_first_node].l = top_first_node;
        nodes[top_first_node].l = -1;
        nodes[top_last_node].r = -1;

        top_kth_node = (top_kth_node == old_top_last_node) ? top_last_node : nodes[top_kth_node].l;

        return;
    }

    int old_bottom_first_node = bottom_first_node;
    int old_bottom_last_node = bottom_last_node;

    bottom_last_node = nodes[old_bottom_last_node].l;
    bottom_first_node = old_bottom_last_node;

    nodes[bottom_first_node].r = old_bottom_first_node;
    nodes[old_bottom_first_node].l = bottom_first_node;
    nodes[bottom_first_node].l = -1;
    nodes[bottom_last_node].r = -1;

    bottom_kth_node = (bottom_kth_node == old_bottom_last_node) ? bottom_last_node : nodes[bottom_kth_node].l;
}

void extend_claw() {
    top_kth_node = nodes[top_kth_node].r;
    bottom_kth_node = nodes[bottom_kth_node].r;
}

void shrink_claw() {
    top_kth_node = nodes[top_kth_node].l;
    bottom_kth_node = nodes[bottom_kth_node].l;
}

void print_result() {
    int top_index = top_first_node;
    int bottom_index = bottom_first_node;
    int a = 0;
    int b = 0;

    while (top_index != -1) {
        cout << candy_string[top_index - 1];
        top_index = nodes[top_index].r;
        a += 1;
    }
    cout << '\n';

    while (bottom_index != -1) {
        cout << candy_string[bottom_index - 1];
        bottom_index = nodes[bottom_index].r;
        b += 1;
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> R >> Q;

    for (int i = 1; i <= 2; i++) {
        string cur;
        cin >> cur;

        candy_string += cur;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++) {
            int cur_no = i * N + j;
            nodes[cur_no] = {cur_no, cur_no - 1, cur_no + 1};
        }

        nodes[1].l = -1;
        nodes[N].r = -1;
        nodes[N + 1].l = -1;
        nodes[N * 2].r = -1;
    }

    top_first_node = 1;
    top_kth_node = R;
    top_last_node = N;
    bottom_first_node = N + 1;
    bottom_kth_node = N + R;
    bottom_last_node = N * 2;

    while (Q--) {
        char command;
        cin >> command;

        if (command == 'S') {
            exchange();
            continue;
        }

        if (command == 'L') {
            int belt_no;
            cin >> belt_no;

            shift_left(belt_no);
            continue;
        }

        if (command == 'R') {
            int belt_no;
            cin >> belt_no;

            shift_right(belt_no);
            continue;
        }

        if (command == 'I') {
            extend_claw();
            continue;
        }

        shrink_claw();
    }

    print_result();
}
