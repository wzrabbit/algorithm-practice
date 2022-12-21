#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

stack<int> bracket_index;
vector<char> answer;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (bracket_index.empty()) {
            bracket_index.push(i);
            answer.push_back('(');
            continue;
        }
        
        cout << "? " << bracket_index.top() << ' ' << i << endl;
        
        string response;
        cin >> response;
        
        if (response == "Yes") {
            bracket_index.pop();
            answer.push_back(')');
        } else {
            bracket_index.push(i);
            answer.push_back('(');
        }
    }
    
    cout << "! ";
    for (int i = 0; i < N; i++) {
        cout << answer[i];
    }
    cout << endl;
}