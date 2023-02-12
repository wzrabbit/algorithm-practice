#include <iostream>
#define INF 1000
using namespace std;

int main() {
    int N;
    cin >> N;
    int bought = 0;
    int prev = 1000;
    
    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        
        if (cur - prev > 0) {
            bought += 1;
        }
        prev = cur;
    }
    
    cout << bought;
}