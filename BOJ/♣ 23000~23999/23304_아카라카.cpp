#include <iostream>
#include <string>
using namespace std;

string S;

bool is_palindrome(int start, int end) {
    int left = start;
    int right = end;
    
    while (left < right) {
        if (S[left] != S[right]) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

bool is_akaraka(int start, int end) {
    int gap = (end - start + 1) / 2;
    
    if (start == end) {
        return true;
    }
    
    if (!is_palindrome(start, end)) {
        return false;
    }
    
    if (!is_akaraka(start, start + gap - 1)) {
        return false;
    }
    
    if (!is_akaraka(end - gap + 1, end)) {
        return false;
    }
    
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> S;
    
    if (is_akaraka(0, S.size() - 1)) {
        cout << "AKARAKA";
    } else {
        cout << "IPSELENTI";
    }
}
