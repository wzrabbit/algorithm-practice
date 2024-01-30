#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int max_number = 0;
        vector<int> answer;

        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            max_number = max(max_number, cur);

            if (max_number == i && i != N) {
                answer.push_back(i);
            }
        }

        cout << answer.size() << '\n';

        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }

        cout << '\n';
    }
}
