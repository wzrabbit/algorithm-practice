#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string text;
int n;
vector<string> frag;
bool dp[500][100000];
int final_dp[100000];
int fail[10000];

void make_kmp_fail(int idx)
{
    for (int l = 0, r = 1; r < frag[idx].length(); r++)
    {
        while (l > 0 && frag[idx][l] != frag[idx][r])
            l = fail[l - 1];
        if (frag[idx][l] == frag[idx][r])
        {
            fail[r] = l + 1;
            l++;
        }
        else
            fail[r] = 0;
    }
}

void do_kmp(int idx)
{
    int pos = 0;
    for (int i = 0; i < text.length(); i++)
    {
        while (pos > 0 && frag[idx][pos] != text[i])
            pos = fail[pos - 1];

        if (frag[idx][pos] == text[i])
        {
            if (pos == frag[idx].length() - 1)
            {
                dp[idx][i] = true;
                pos = fail[pos];
            }
            else
                pos++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> text;
    cin >> n;
    frag.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> frag[i];
        make_kmp_fail(i);
        do_kmp(i);
    }

    for (int i = 0; i < text.length(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
                final_dp[i] = max(final_dp[i], final_dp[i - 1]);

            if (dp[j][i] == true)
            {
                int len = frag[j].length();
                int prev = i - len;

                if (prev >= 0)
                    final_dp[i] = max(final_dp[prev] + len, final_dp[i]);
                else
                    final_dp[i] = max(len, final_dp[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < text.length(); i++)
        ans = max(final_dp[i], ans);

    cout << ans;
}