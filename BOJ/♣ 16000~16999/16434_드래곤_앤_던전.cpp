#include <iostream>
#include <climits>
using namespace std;

long long int mode[123457];
long long int atk_[123457];
long long int hp_[123457];
long long int room, startPower;

bool doAdventure(long long int maxHp)
{
    long long int hp = maxHp;
    long long int power = startPower;

    for (int i = 0; i < room; i++)
    {
        if (mode[i] == 1)
        {
            long long int monsterPower = atk_[i];
            long long int monsterHp = hp_[i];

            long long int m = monsterHp / power + 1;
            if (monsterHp % power == 0)
                m--;
            long long int p = hp / monsterPower + 1;
            if (hp % monsterPower == 0)
                p--;

            if (p >= m)
            {
                hp -= (m - 1) * monsterPower;
            }
            else
                return false;
        }
        else
        {
            power += atk_[i];
            hp += hp_[i];
            if (hp > maxHp)
                hp = maxHp;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> room >> startPower;
    for (int i = 0; i < room; i++)
    {
        cin >> mode[i] >> atk_[i] >> hp_[i];
    }
    long long int start = 1;
    long long int end = 123456000000000000;
    long long int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (doAdventure(mid))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << start;
}