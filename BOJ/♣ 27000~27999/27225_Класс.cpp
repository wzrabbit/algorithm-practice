#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int boy, girl;
    cin >> boy >> girl;

    cout << min(boy, girl) * 2 + (boy + girl) % 2;
}