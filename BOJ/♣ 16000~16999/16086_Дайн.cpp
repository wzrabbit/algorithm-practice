#include <iostream>
using namespace std;

bool is_occupied[200000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        is_occupied[(N + i - cur) % N] = true;
    }
    
    for (int i = 0; i < N; i++) {
        if (is_occupied[i] == false) {
            cout << i;
            return 0;
        }
    }
    
    cout << -1;
}