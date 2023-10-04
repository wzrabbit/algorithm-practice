#include <algorithm>
#include <iostream>
using namespace std;

int arr[5];

int main() {
    int avg = 0;

    for (int i = 1; i <= 5; i++) {
        cin >> arr[i];
        avg += arr[i];
    }

    sort(arr + 1, arr + 6);
    avg /= 5;

    cout << avg << '\n'
         << arr[3];
}