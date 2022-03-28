#include <iostream>
using namespace std;

int n;
int num_list[12];
int max_ = -2100000000;
int min_ = 2100000000;

void backtracking(int value, int count, int plus, int minus, int mul, int div)
{
    if (count == n)
    {
        if (value > max_)
            max_ = value;
        if (value < min_)
            min_ = value;
        return;
    }

    if (plus > 0)
        backtracking(value + num_list[count + 1], count + 1, plus - 1, minus, mul, div);
    if (minus > 0)
        backtracking(value - num_list[count + 1], count + 1, plus, minus - 1, mul, div);
    if (mul > 0)
        backtracking(value * num_list[count + 1], count + 1, plus, minus, mul - 1, div);
    if (div > 0)
        backtracking(value / num_list[count + 1], count + 1, plus, minus, mul, div - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num_list[i];
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    backtracking(num_list[1], 1, a, b, c, d);

    cout << max_ << '\n'
         << min_;
}