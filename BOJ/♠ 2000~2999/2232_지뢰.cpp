#include <iostream>
#include <vector>
using namespace std;

int mines[50002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> mines[i];
    }

    for (int i = 1; i <= N; i++) {
        if (mines[i] >= mines[i - 1] && mines[i] >= mines[i + 1]) {
            cout << i << '\n';
        }
    }
}
