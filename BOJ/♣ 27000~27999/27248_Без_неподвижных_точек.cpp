#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int permutation[1001];
bool is_used[1001];
vector<int> state;
int N, T;

void make_permutation(int cur, int len) {
    if (T <= 0) {
        return;
    }
    
    state.push_back(cur);
    is_used[cur] = true;
    
    if (len == N) {
        for (int i = 1; i <= N; i++) {
            cout << state[i] << ' ';
        }
        
        cout << '\n';
        T -= 1;
    } else {
        for (int i = 1; i <= N; i++) {
            if (i != len + 1 && !is_used[i]) {
                make_permutation(i, len + 1);
            }
        }
    }
    
    state.pop_back();
    is_used[cur] = false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> T;
    
    make_permutation(0, 0);
}