#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll scores[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll cur_score = 1;
    ll total = 0;
    ll N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    
    sort(scores, scores + N);
    
    for (int i = 0; i < N; i++) {
        cur_score = min(cur_score, scores[i]);
        total += max(0ll, scores[i] - cur_score);
        cur_score += 1;
    }
    
    cout << total;
}