#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<int> hotels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
ll dp[34];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int low, high;
    cin >> low >> high;

    dp[0] = 1;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        hotels.push_back(cur);
    }

    sort(hotels.begin(), hotels.end());

    for (size_t i = 1; i < hotels.size(); i++) {
        for (int j = 0; j < i; j++) {
            int dist = hotels[i] - hotels[j];
            if (dist >= low && dist <= high) {
                dp[i] += dp[j];
            }
        }
    }

    cout << dp[hotels.size() - 1];
}