#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

ll prefix[10001];
ll answer[10001];
set<pair<int, int>> ban;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (ban.find(make_pair(j, i)) == ban.end())
            {
                cout << "? " << j << ' ' << i << endl;

                ll sum_, l, r;
                cin >> sum_ >> l >> r;

                answer[i] = sum_ - prefix[i - 1] + prefix[j - 1];
                prefix[i] = prefix[i - 1] + answer[i];
                ban.insert(make_pair(l, r));
                break;
            }
        }
    }

    cout << "!\n";
    for (int i = 1; i <= N; i++)
        cout << answer[i] << ' ';
    cout << endl;
}