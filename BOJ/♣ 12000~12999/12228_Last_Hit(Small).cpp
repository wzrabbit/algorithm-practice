#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// dp[잡고 있는 몹][남은 체력][공격 기회] = 골드;
int dp[4][201][42];
int mob_info[4][2]; // HP, Gold
int diana, turret, N;

int top_down(int target, int hp, int chance)
{
    int &cur = dp[target][hp][chance];
    if (cur != -1)
        return cur;

    cur = 0;
    if (hp == 0 && target < N - 1)
        cur = top_down(target + 1, mob_info[target + 1][0], chance);

    if (hp > 0)
    {
        int diana_hit_hp = max(0, hp - diana);
        int turret_hit_hp = max(0, hp - turret);
        int gold = 0;

        if (diana_hit_hp == 0)
            gold += mob_info[target][1];

        cur = max(
            (chance > 0) ? top_down(target, diana_hit_hp, chance - 1) + gold : 0,
            top_down(target, turret_hit_hp, chance + 1));
    }

    return cur;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        fill(&dp[0][0][0], &dp[3][200][42], -1);
        cin >> diana >> turret >> N;

        for (int i = 0; i < N; i++)
            cin >> mob_info[i][0] >> mob_info[i][1];

        cout << "Case #" << t << ": " << top_down(0, mob_info[0][0], 1) << '\n';
    }
}