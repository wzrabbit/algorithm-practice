#include <iostream>
#include <vector>
using namespace std;

struct Path {
    vector<int> p;
    int n;
};

Path get_path(int size, int start) {
    if (size == 2) {
        return start == 1 ? Path{{1, 2}, 1} : Path{{2, 1}, 2};
    }

    vector<int> path(size, 0);

    bool should_go_inner_first = start > size / 4 && start <= 3 * size / 4;

    if (should_go_inner_first) {
        Path inner_result = get_path(size / 2, start - size / 4);
        vector<int> inner_path = inner_result.p;
        int next_start = inner_result.n;

        for (size_t i = 0; i < size / 2; i++) {
            path[i + size / 4] = inner_path[i];
        }

        Path outer_result = get_path(size / 2, next_start);
        vector<int> outer_path = outer_result.p;

        for (size_t i = 0; i < size / 4; i++) {
            path[i] = outer_path[i];
        }

        for (size_t i = 0; i < size / 4; i++) {
            path[i + size * 3 / 4] = outer_path[i + size / 4];
        }
    }
}

void print_answer(int size, int start) {
    vector<int> result = get_path(true, size, start).p;

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, S;
    cin >> N >> S;

    solve(N, true, 1, S);
}