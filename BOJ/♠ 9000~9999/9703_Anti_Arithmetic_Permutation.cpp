#include <iostream>
using namespace std;

int arr[50];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        bool success = true;
        
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (arr[j] - arr[i] == arr[k] - arr[j]) {
                        success = false;
                    }
                }
            }
        }
        
        if (success) {
            cout << "Case #" << t << ": YES\n";
        } else {
            cout << "Case #" << t << ": NO\n";
        }
    }
}