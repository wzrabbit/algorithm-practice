#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double N;
    cin >> N;

    double result = sqrt(N) * 4;

    cout << fixed << setprecision(7) << result;

    return 0;
}
