#include <iostream>
using namespace std;

int main() {
    int W, H;
    cin >> W >> H;

    if (W * H % 2 == 0) {
        cout << W * H / 2 << ".0";
    } else {
        cout << W * H / 2 << ".5";
    }
}