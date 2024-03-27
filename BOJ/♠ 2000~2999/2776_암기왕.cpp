#include <iostream>
#include <set>
using namespace std;

set<int> questions;
int answers[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        questions.clear();

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            questions.insert(cur);
        }

        int M;
        cin >> M;

        for (int i = 1; i <= M; i++) {
            int cur;
            cin >> cur;

            if (questions.find(cur) == questions.end()) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
    }
}
