#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

deque<int> upper, lower;
vector<int> mid;
int N, Q, K;
bool is_reversed = false;

void perform_query_add(int item) {
    if (is_reversed) {
        lower.push_front(item);
        return;
    }

    upper.push_back(item);
}

void perform_query_sort() {
    while (!upper.empty()) {
        mid.push_back(upper.back());
        upper.pop_back();
    }

    while (!lower.empty()) {
        mid.push_back(lower.back());
        lower.pop_back();
    }

    is_reversed = false;
}

void perform_query_reverse() {
    is_reversed = !is_reversed;
}

void print_answer() {
    sort(mid.begin(), mid.end(), greater<int>());
    vector<int> order;

    if (is_reversed) {
        while (!lower.empty()) {
            order.push_back(lower.front());
            lower.pop_front();
        }

        for (size_t i = 0; i < mid.size(); i++) {
            order.push_back(mid[i]);
        }

        while (!upper.empty()) {
            order.push_back(upper.front());
            upper.pop_front();
        }
    } else {
        while (!upper.empty()) {
            order.push_back(upper.back());
            upper.pop_back();
        }

        for (int i = (int)mid.size() - 1; i >= 0; i--) {
            order.push_back(mid[i]);
        }

        while (!lower.empty()) {
            order.push_back(lower.back());
            lower.pop_back();
        }
    }

    cout << order[K - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q >> K;

    while (Q--) {
        int q;
        cin >> q;

        if (q == 0) {
            int n;
            cin >> n;
            perform_query_add(n);
        } else if (q == 1) {
            perform_query_sort();
        } else {
            perform_query_reverse();
        }
    }

    print_answer();
}
