#include <iostream>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int prefix[200000][26];
string S;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> S;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (i > 0)
        {
            for (int j = 0; j < 26; j++)
                prefix[i][j] = prefix[i - 1][j];
        }

        prefix[i][S[i] - 'a']++;
    }

    int Q, start, end;
    char alphabet;
    cin >> Q;
    while (Q--)
    {
        cin >> alphabet >> start >> end;
        cout << prefix[end][alphabet - 'a'] - (start > 0 ? prefix[start - 1][alphabet - 'a'] : 0) << '\n';
    }
}