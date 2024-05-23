#include <algorithm>
#include <iostream>
using namespace std;

int frequencies[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        frequencies[cur] += 1;
    }

    int max_frequency = 0;

    for (int i = 1; i <= 1000; i++) {
        max_frequency = max(frequencies[i], max_frequency);
    }

    cout << max_frequency;
}
