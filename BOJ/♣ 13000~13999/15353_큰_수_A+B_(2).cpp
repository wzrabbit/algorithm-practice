#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string A, B;
    stack<int> result;
    cin >> A >> B;
    
    int pointer_A = A.length() - 1;
    int pointer_B = B.length() - 1;
    int extra = 0;
    
    while (pointer_A >= 0 || pointer_B >= 0 || extra > 0) {
        int value_A = 0;
        int value_B = 0;
        
        if (pointer_A >= 0) {
            value_A = A[pointer_A] - '0';
            pointer_A--;
        }
        
        if (pointer_B >= 0) {
            value_B = B[pointer_B] - '0';
            pointer_B--;
        }
        
        int frag_result = value_A + value_B + extra;
        result.push(frag_result % 10);
        extra = frag_result / 10;
    }
    
    while (!result.empty()) {
        int current_digit = result.top();
        result.pop();
        cout << current_digit;
    }
}