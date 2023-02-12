#include <iostream>
#include <string>
using namespace std;

string words[15];
string answer_order[15];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int set_no = 1;
    
    while (true) {
        int N;
        cin >> N;
        
        if (N == 0) {
            break;
        }
        
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        
        cout << "SET " << set_no++ << '\n';
        
        int l = 0;
        int r = N - 1;
        int i = 0;
        
        while (l <= r) {
            answer_order[l] = words[i++];
            if (l < r) {
                answer_order[r] = words[i++];
            }
            
            l++;
            r--;
        }
        
        for (int i = 0; i < N; i++) {
            cout << answer_order[i] << '\n';
        }
    }
}