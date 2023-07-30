#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000001
using namespace std;

vector<int> dominoes;
vector<int> gaps;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, min_range, max_range;
    cin >> N >> min_range >> max_range;
    
    for (int i = 0; i < N; i++) {
        int domino;
        cin >> domino;
        dominoes.push_back(domino);
    }
    
    sort(dominoes.begin(), dominoes.end());
    
    for (int i = 0; i < N - 1; i++) {
        gaps.push_back(dominoes[i + 1] - dominoes[i]);
    }
    gaps.push_back(0);
    sort(gaps.begin(), gaps.end(), greater<int>());
    
    int answer = INF;
    for (int i = 0; i < N - 1; i++) {
        if (gaps[i] != gaps[i + 1] && ) {
            if ()
        }
    }
    cout << '\n';
}