#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string flip(string num)
{
    string reversedNum = "";
    for (int i = num.length() - 1; i >= 0; i--)
    {
        if (num[i] == '6')
            reversedNum += '9';
        else if (num[i] == '9')
            reversedNum += '6';
        else
            reversedNum += num[i];
    }
    return reversedNum;
}

bool sorter(string a, string b)
{
    if (stoll(flip(a + b)) > stoll(flip(b + a)))
        return true;
    return false;
}

string onlyBigSorter(string a, string b)
{
    if (a.length() > b.length())
        return a;
    else if (a.length() < b.length())
        return b;
    if (stoll(flip(a)) > stoll(flip(b)))
        return a;
    else
        return b;
}

string arr[100010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    string onlyBig = arr[0];
    for (int i = 1; i < n; i++)
    {
        onlyBig = onlyBigSorter(onlyBig, arr[i]);
    }
    arr[n] = onlyBig;

    sort(arr, arr + n + 1, sorter);
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i];
    }
}