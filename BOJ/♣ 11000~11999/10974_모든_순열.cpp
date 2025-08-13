#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vec;

    for (int i = 1; i <= N; i++) {
        vec.push_back(i);
    }

    do {
        for (int i = 0; i < N; i++) {
            cout << vec[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(vec.begin(), vec.end()));
}
