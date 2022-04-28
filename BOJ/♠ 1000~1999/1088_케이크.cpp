#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

struct cake_data
{
    double scale, div;
};
vector<cake_data> cake;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num, cut;
    double c;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> c;
        cake.push_back({c, 1});
    }
    cin >> cut;

    double min_ = 1000000001;
    double max_ = 0;
    int max_id = 0;
    for (int i = 0; i < num; i++)
    {
        double current = cake[i].scale;
        if (current > max_)
            max_ = current;
        if (current < min_)
            min_ = current;
    }
    double answer = max_ - min_;

    while (cut--)
    {
        min_ = 1000000001;
        max_ = 0;
        max_id = 0;
        for (int i = 0; i < num; i++)
        {
            double current = cake[i].scale / cake[i].div;
            if (current > max_)
            {
                max_ = current;
                max_id = i;
            }
        }

        cake[max_id].div++;

        max_ = 0;
        for (int i = 0; i < num; i++)
        {
            double current = cake[i].scale / cake[i].div;
            if (current > max_)
                max_ = current;
            if (current < min_)
                min_ = current;
        }
        if (max_ - min_ < answer)
            answer = max_ - min_;
    }

    cout << setprecision(15) << answer;
}