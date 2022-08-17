#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double X;
    cin >> X;
    cout << fixed << setprecision(7) << 3.785411784 * 100000 / (X * 1609.344);
}