#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> elements;

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;

        if (cur % 2 == 0) {
            elements.push_back(i);
        }
    }

    ll left_moves = 0;
    ll right_moves = 0;

    for (size_t i = 0; i < elements.size(); i++) {
        left_moves += elements[i] - i;
        right_moves += N - elements.size() + i - elements[i];
    }

    cout << min(left_moves, right_moves);
}