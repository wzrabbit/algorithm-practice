#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int R, C;
    int answer = 1;
    cin >> R >> C;
    
    while (R != C) {
        if (R < C) {
            swap(R, C);
            continue;
        }
        
        R -= C;
        answer += 1;
    }
    
    cout << answer;
}