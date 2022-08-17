#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

ll width, height, rival, cnt, win_game;
vector<ll> partition_;
vector<ll> factorial = {1};

ll get_gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;

    return get_gcd(b, a % b);
}

void calculate()
{
    vector<ll> group_cnt(21, 0);
    ll move_cnt = 0;
    ll cases = 1;
    ll choose_left = width * height;
    for (size_t i = 0; i < partition_.size(); i++)
    {
        ll cur = partition_[i];

        group_cnt[cur]++;
        move_cnt += cur - 1;

        if (cur > 1)
        {
            for (int j = 0; j < cur; j++)
                cases *= choose_left--;
            cases = cases / cur / group_cnt[cur];
        }
        else
            choose_left--;
    }

    if (move_cnt < rival)
        win_game += cases;
}

void make_partition(ll cur, ll remain)
{
    partition_.push_back(cur);

    if (remain == 0)
    {
        calculate();
        partition_.pop_back();
        return;
    }

    ll next_remain = min(remain, cur);

    for (int i = 1; i <= next_remain; i++)
        make_partition(i, remain - i);

    partition_.pop_back();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll T;
    cin >> T;

    for (int i = 1; i <= 20; i++)
        factorial.push_back(factorial.back() * i);

    while (T--)
    {
        cin >> width >> height >> rival;
        win_game = 0;

        for (int i = width * height; i >= 1; i--)
            make_partition(i, width * height - i);

        ll all_game = factorial[width * height];

        if (win_game == 0)
            cout << "0\n";
        else if (win_game == all_game)
            cout << "1\n";
        else
        {
            ll gcd = get_gcd(win_game, all_game);
            cout << win_game / gcd << "/" << all_game / gcd << '\n';
        }
    }
}