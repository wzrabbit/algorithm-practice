#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double prefix_l[200002];
double prefix_r[200002];
double x[200002];
double y[200002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> y[i];
    }

    for (int i = 2; i <= N; i++) {
        prefix_l[i] = prefix_l[i - 1];
        prefix_r[i] = prefix_r[i - 1];
        double dist = sqrt(pow(x[i] - x[i - 1], 2) + pow(y[i] - y[i - 1], 2));

        if (y[i] > y[i - 1]) {
            prefix_r[i] += dist * 3;
            prefix_l[i] += dist;
        } else if (y[i] == y[i - 1]) {
            prefix_r[i] += dist * 2;
            prefix_l[i] += dist * 2;
        } else {
            prefix_r[i] += dist;
            prefix_l[i] += dist * 3;
        }
    }

    for (int i = 1; i <= Q; i++) {
        int start, end;
        cin >> start >> end;

        if (start > end) {
            swap(start, end);
            cout << fixed << setprecision(5) << prefix_l[end] - prefix_l[start] << '\n';
        } else {
            cout << fixed << setprecision(5) << prefix_r[end] - prefix_r[start] << '\n';
        }
    }
}