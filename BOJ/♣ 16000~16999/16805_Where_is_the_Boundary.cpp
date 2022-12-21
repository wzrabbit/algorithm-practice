#include <iostream>
using namespace std;

char land[102][10002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int C, R;
    cin >> C >> R;
    
    for (int r = 1; r <= R; r++) {
        cin >> (land[r] + 1);
    }
    
    int left_error = 0;
    int right_error = 0;
    int best_error;
    int best_index = 0;
    
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (land[r][c] == 'W') {
                right_error += 1;
            }
        }
    }
    best_error = right_error;
    
    for (int c = 1; c <= C; c++) {
        for (int r = 1; r <= R; r++) {
            if (land[r][c] == 'W') {
                right_error -= 1;
            } else {
                left_error += 1;
            }
        }
        
        if (left_error + right_error < best_error) {
            best_error = left_error + right_error;
            best_index = c;
        }
    }
    
    cout << best_index << ' ' << best_index + 1;
}