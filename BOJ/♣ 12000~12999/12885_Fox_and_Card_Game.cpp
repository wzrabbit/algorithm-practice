#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> candidates;
    int score = 0;
    int sum = 0;

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int D;
        cin >> D;

        for (int j = 1; j <= D; j++) {
            int cur;
            cin >> cur;
            sum += cur;

            if (j <= D / 2) {
                score += cur;
                continue;
            }

            if (D % 2 == 1 && j == D / 2 + 1) {
                candidates.push_back(cur);
            }
        }
    }

    sort(candidates.begin(), candidates.end(), greater<int>());

    for (size_t i = 0; i < candidates.size(); i += 2) {
        score += candidates[i];
    }

    cout << score << ' ' << sum - score;
}
