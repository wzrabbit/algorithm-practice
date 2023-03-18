#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    int N;
    cin >> N;

    ll result = 1;
    for (int i = 2; i <= N; i++) {
        result *= i;
    }

    cout << result;
}