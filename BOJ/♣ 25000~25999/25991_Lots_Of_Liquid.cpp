#include <cmath>
#include <iomanip>
#include <iostream>
typedef long double ld;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cout << fixed << setprecision(10);

    int N;
    cin >> N;

    ld total_area = 0;

    for (int i = 1; i <= N; i++) {
        ld cur;
        cin >> cur;
        total_area += cur * cur * cur;
    }

    cout << cbrt(total_area);
}
