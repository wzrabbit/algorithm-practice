#include <iostream>
using namespace std;

int scale[50001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        scale[cur] += 1;
    }
    
    int answer = 0;
    for (int i = 1; i <= 50000; i++) {
        answer = max(answer, scale[i]);
    }
    
    cout << answer;
}