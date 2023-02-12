#include <iostream>
#include <algorithm>
using namespace std;

int numbers[50001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }
    
    int odd_count = 0;
    int best_length = 0;
    int l = 1;
    
    for (int r = 1; r <= N; r++) {
        if (numbers[r] % 2 == 1) {
            odd_count += 1;
        }
        
        while (odd_count > K) {
            if (numbers[l] % 2 == 1) {
                odd_count -= 1;
            }
            l += 1;
        }
        
        best_length = max(best_length, r - l + 1 - odd_count);
    }
    
    cout << best_length;
}