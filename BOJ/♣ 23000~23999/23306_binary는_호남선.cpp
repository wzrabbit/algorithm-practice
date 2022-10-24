#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, l, r;
    cin >> N;

    cout << "? " << 1 << endl;
    cin >> l;

    cout << "? " << N << endl;
    cin >> r;

    if (l == r)
        cout << "! 0" << endl;
    else if (l > r)
        cout << "! -1" << endl;
    else
        cout << "! 1" << endl;
}