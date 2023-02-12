#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string exp;
    cin >> exp;

    for (size_t i = 0; i < exp.size(); i++) {
        if (exp[i] == '(' || exp[i] == ')') {
            cout << "(0)+";
        } else if (exp[i] >= '0' && exp[i] <= '9') {
            cout << exp[i] << '+';
        } else {
            cout << "0+";
        }
    }

    cout << "0";
}