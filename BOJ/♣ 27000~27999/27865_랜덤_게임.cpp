#include <iostream>
using namespace std;

int main() {
    int _;
    cin >> _;

    for (int i = 1; i <= 20000; i++) {
        cout << "? 1" << endl;

        char result;
        cin >> result;

        if (result == 'Y') {
            cout << "! 1" << endl;
            break;
        }
    }
}