#include <iostream>
using namespace std;

int main() {
    int a, b, total;
    scanf("%d + %d = %d", &a, &b, &total);
    
    if (a + b == total) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}