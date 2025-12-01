#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> digits;
vector<int> state;
int N, M;

void backtrack(int step) {
    if (step == M) {
        for (int cur : state) {
            cout << cur << ' ';
        }
        cout << '\n';
        return;
    }

    for (int cur : digits) {
        state.push_back(cur);
        backtrack(step + 1);
        state.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        digits.push_back(cur);
    }

    sort(digits.begin(), digits.end());
    auto last = unique(digits.begin(), digits.end());
    digits.erase(last, digits.end());

    backtrack(0);
}
