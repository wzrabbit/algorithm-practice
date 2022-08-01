#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll arr_A[1000];
ll arr_B[1000];
vector<ll> pocket;

void print_result()
{
    cout << pocket.size() << ' ';
    for (int i = 0; i < pocket.size(); i++)
        cout << pocket[i] << ' ';
    cout << '\n';
    pocket.clear();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll L, S, len_A, len_B;
    cin >> L >> S;

    cin >> len_A;
    for (int i = 0; i < len_A; i++)
        cin >> arr_A[i];

    cin >> len_B;
    for (int i = 0; i < len_B; i++)
        cin >> arr_B[i];

    // Sum
    int a = 0, b = 0;
    while (a < len_A && b < len_B)
    {
        if (abs(arr_A[a]) < abs(arr_B[b]))
        {
            pocket.push_back(arr_A[a]);
            a++;
        }
        else if (abs(arr_A[a]) > abs(arr_B[b]))
        {
            pocket.push_back(arr_B[b]);
            b++;
        }
        else
        {
            if (arr_A[a] + arr_B[b] != 0)
                pocket.push_back(arr_A[a]);

            a++;
            b++;
        }
    }

    while (a < len_A)
    {
        pocket.push_back(arr_A[a]);
        a++;
    }

    while (b < len_B)
    {
        pocket.push_back(arr_B[b]);
        b++;
    }

    print_result();

    // Product
    a = 0, b = 0;
    while (a < len_A && b < len_B)
    {
        if (abs(arr_A[a]) == abs(arr_B[b]))
        {
            if ((arr_A[a] > 0 && arr_B[b] > 0) || (arr_A[a] < 0 && arr_B[b] < 0))
                pocket.push_back(abs(arr_A[a]));
            else
                pocket.push_back(-abs(arr_A[a]));
            a++;
            b++;
        }
        else if (abs(arr_A[a]) < abs(arr_B[b]))
            a++;
        else
            b++;
    }

    print_result();

    // Shift-A
    a = 0;
    while (a < len_A && abs(arr_A[a]) <= S)
        a++;

    for (int i = a; i < len_A; i++)
    {
        if (arr_A[i] > 0)
            pocket.push_back(arr_A[i] - S);
        else
            pocket.push_back(arr_A[i] + S);
    }

    for (int i = 0; i < a; i++)
    {
        if (arr_A[i] > 0)
            pocket.push_back(arr_A[i] + L - S);
        else
            pocket.push_back(arr_A[i] - L + S);
    }

    print_result();

    // Shift-B
    b = 0;
    while (b < len_B && abs(arr_B[b]) <= S)
        b++;

    for (int i = b; i < len_B; i++)
    {
        if (arr_B[i] > 0)
            pocket.push_back(arr_B[i] - S);
        else
            pocket.push_back(arr_B[i] + S);
    }

    for (int i = 0; i < b; i++)
    {
        if (arr_B[i] > 0)
            pocket.push_back(arr_B[i] + L - S);
        else
            pocket.push_back(arr_B[i] - L + S);
    }

    print_result();
}