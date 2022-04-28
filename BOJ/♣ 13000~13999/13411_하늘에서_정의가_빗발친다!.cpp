#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct v_data
{
    int no;
    double dist;
};
vector<v_data> data_list;

bool compare(v_data a, v_data b)
{
    if (a.dist != b.dist)
        return a.dist < b.dist;
    else
        return a.no < b.no;
}

int main()
{
    int n;
    cin >> n;
    data_list.resize(n);

    for (int i = 0; i < n; i++)
    {
        double x, y, speed;
        cin >> x >> y >> speed;
        data_list[i].dist = sqrt(x * x + y * y) / speed;
        data_list[i].no = i + 1;
    }

    sort(data_list.begin(), data_list.end(), compare);

    for (int i = 0; i < data_list.size(); i++)
        cout << data_list[i].no << '\n';
}