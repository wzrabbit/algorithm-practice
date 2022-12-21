#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> know_set, lyrics_set;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        know_set.insert(word);
    }
    
    int M;
    cin >> M;
    
    for (int i = 1; i <= M; i++) {
        string word;
        cin >> word;
        if (know_set.count(word) == 1) {
            lyrics_set.insert(word);
        }
        
        if (lyrics_set.size() * 2 >= know_set.size()) {
            cout << i;
            break;
        }
    }
}