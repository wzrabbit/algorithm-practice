#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

bool is_not_prime(ll num)
{
    if (num == 1)
        return true;

    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return true;
    }

    return false;
}

int main()
{
    string num;
    cin >> num;

    if (is_not_prime(stoll(num)))
    {
        cout << "no";
        return 0;
    }

    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '6')
            num[i] = '9';
        else if (num[i] == '9')
            num[i] = '6';
        else if (num[i] == '3' || num[i] == '4' || num[i] == '7')
        {
            cout << "no";
            return 0;
        }
    }
    reverse(num.begin(), num.end());

    if (is_not_prime(stoll(num)))
        cout << "no";
    else
        cout << "yes";
}