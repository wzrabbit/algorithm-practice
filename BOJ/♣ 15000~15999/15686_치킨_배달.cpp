#include < iostream >
#include < algorithm >
#include < vector >
using namespace std;

struct loc
{
    int row, col;
};
vector<loc> chicken_list;
vector<loc> house_list;
vector<int> chosen_list;
int house_count = 0;
int chicken_count = 0;
int best_dist = 2000000000;
int width, limit;

void calculate_dist()
{
    int min_ = 0;
    for (int h = 1; h <= house_count; h++)
    {
        int one_min = 2000000000;
        for (int l = 1; l <= limit; l++)
        {
            int one_current = 0;
            one_current += abs(chicken_list[chosen_list[l]].row - house_list[h].row);
            one_current += abs(chicken_list[chosen_list[l]].col - house_list[h].col);
            if (one_current < one_min)
                one_min = one_current;
        }
        min_ += one_min;
    }
    if (min_ < best_dist)
        best_dist = min_;
}

void make_set(int current, int len)
{
    chosen_list.push_back(current);
    if (len == limit)
    {
        calculate_dist();
        chosen_list.pop_back();
        return;
    }

    for (int i = current + 1; i <= chicken_count - limit + len + 1; i++)
    {
        make_set(i, len + 1);
    }

    chosen_list.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d;
    cin >> width >> limit;
    house_list.push_back({-1, -1});
    chicken_list.push_back({-1, -1});
    chosen_list.push_back(-1);

    for (int r = 1; r <= width; r++)
    {
        for (int c = 1; c <= width; c++)
        {
            cin >> d;
            if (d == 1)
            {
                house_list.push_back({r, c});
                house_count++;
            }
            else if (d == 2)
            {
                chicken_list.push_back({r, c});
                chicken_count++;
            }
        }
    }

    for (int i = 1; i <= chicken_count - limit + 1; i++)
        make_set(i, 1);
    cout << best_dist;
}