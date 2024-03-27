#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> wrong;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        if (arr[i] % 2 != i % 2) {
            wrong.push_back(i);
        }
    }

    if (wrong.size() == 2 && arr[wrong[0]] % 2 != arr[wrong[1]] % 2) {
        cout << wrong[0] << ' ' << wrong[1];
    } else if (wrong.size() == 0 && N >= 3) {
        cout << "1 3";
    } else {
        cout << "-1 -1";
    }
}
