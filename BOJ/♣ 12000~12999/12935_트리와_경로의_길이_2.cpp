#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
};

int main() {
    vector<Edge> answer = {{0, 1}, {1, 2}};
    int id = 2;
    int branch_count = 1;

    int S;
    cin >> S;

    while (true) {
        if (S - branch_count * 2 < 0) {
            break;
        }

        answer.push_back({0, id + 1});
        answer.push_back({id + 1, id + 2});
        id += 2;

        S -= branch_count * 2;
        branch_count += 1;
    }

    for (int i = 1; i <= S; i++) {
        answer.push_back({id, id + 1});
        id += 1;
    }

    cout << answer.size() + 1 << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].u << ' ' << answer[i].v << '\n';
    }
}