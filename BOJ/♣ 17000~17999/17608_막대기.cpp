#include <iostream>
using namespace std;

int heights[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int visible_count = 0;
    int max_height = 0;

    for (int i = 1; i <= N; i++) {
        cin >> heights[i];
    }

    for (int i = N; i >= 1; i--) {
        if (heights[i] > max_height) {
            max_height = heights[i];
            visible_count += 1;
        }
    }

    cout << visible_count;
}