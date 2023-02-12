#include <iostream>
#include <algorithm>
using namespace std;

int teams[12];

int main() {
    int N, S, R;
    cin >> N >> S >> R;
    
    for (int i = 1; i <= S; i++) {
        int minus_no;
        cin >> minus_no;
        teams[minus_no] -= 1;
    }
    
    for (int i = 1; i <= R; i++) {
        int plus_no;
        cin >> plus_no;
        teams[plus_no] += 1;
    }
    
    for (int i = 1; i <= N; i++) {
        if (teams[i] != 1) {
            continue;
        }
        
        if (teams[i - 1] == -1) {
            teams[i - 1] = 0;
            teams[i] = 0;
            continue;
        }
        
        if (teams[i + 1] == -1) {
            teams[i + 1] = 0;
            teams[i] = 0;
        }
    }
    
    int cant_start_count = 0;
    for (int i = 1; i <= N; i++) {
        if (teams[i] == -1) {
            cant_start_count += 1;
        }
    }
    
    cout << cant_start_count;
}