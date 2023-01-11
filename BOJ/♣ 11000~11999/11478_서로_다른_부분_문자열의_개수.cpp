#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    set<string> words;
    cin >> S;

    for (size_t i = 0; i < S.size(); i++) {
        string frag_S = "";

        for (size_t j = i; j < S.size(); j++) {
            frag_S += S[j];
            words.insert(frag_S);
        }
    }

    cout << words.size();
}