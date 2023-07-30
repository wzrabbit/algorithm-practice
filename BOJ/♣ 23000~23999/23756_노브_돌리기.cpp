#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum_angle = 0;
    int before;
    cin >> before;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        int gap = abs(cur - before);

        sum_angle += min(gap, 360 - gap);
        before = cur;
    }

    cout << sum_angle;
}