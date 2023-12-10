#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a = -1;
    int b = -1;

    for (int i = 1; i <= 9; i++) {
        cout << "? A " << i << endl;

        bool is_correct;
        cin >> is_correct;

        if (is_correct) {
            a = i;
            break;
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << "? B " << i << endl;

        bool is_correct;
        cin >> is_correct;

        if (is_correct) {
            b = i;
            break;
        }
    }

    cout << "! " << a + b << endl;
}
