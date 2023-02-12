#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;
        
        string S;
        cin >> S;
        
        int l = 0;
        int r = N - 1;
        int goodness = 0;
        
        while (l < r) {
            if (S[l] != S[r]) {
                goodness += 1;
            }
            
            l += 1;
            r -= 1;
        }
        
        cout << "Case #" << t << ": " << abs(goodness - K) << '\n';
    }
}