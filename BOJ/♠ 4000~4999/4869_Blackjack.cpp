#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int get_value(string card)
{
    if (card == "A")
        return 11;
    else if (card == "T" || card == "K" || card == "Q" || card == "J")
        return 10;
    else
        return stoi(card);
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        string d, p1, p2;
        int d_, p1_, p2_;
        vector<int> deck(12, n * 4);
        cin >> d >> p1 >> p2;

        d_ = get_value(d);
        p1_ = get_value(p1);
        p2_ = get_value(p2);

        deck[10] *= 4;
        deck[d_] -= 1;
        deck[p1_] -= 1;
        deck[p2_] -= 1;

        if (p1_ == 11 && p2_ == 11)
            p2_ = 1;

        int sum_ = 0, prob = 0;
        for (int i = 2; i <= 11; i++)
            sum_ += deck[i];

        for (int i = 2; i <= 11; i++)
        {
            int choosed = i;
            if (d_ == 11 && i == 11)
                choosed = 1;

            if (d_ + choosed < p1_ + p2_)
                prob += deck[i];
        }

        double answer = round((double)prob / (double)sum_ * 100000) / 1000;
        printf("%.3f%\n", answer);
    }
}