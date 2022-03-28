#include <iostream>
#include <string>
using namespace std;
long long int num;
long long int currentNum = 0;
long long int gap = 1000000000001;
long long int answerNum;
bool kill = false;
int goal = 0;
int visited[10] = {};

void backTracking(int current, int len)
{
    if (kill)
        return;
    visited[current] = true;
    currentNum = currentNum * 10 + current;
    if (len == goal)
    {
        if (abs(num - currentNum) < gap)
        {
            gap = abs(num - currentNum);
            answerNum = currentNum;
        }
        if (currentNum >= num)
        {
            kill = true;
        }
        visited[current] = false;
        currentNum /= 10;
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (visited[i] == false)
        {
            backTracking(i, len + 1);
        }
    }
    visited[current] = false;
    currentNum /= 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    if (num <= 10)
    {
        cout << num;
    }
    else if (num >= 9876543210)
    {
        cout << 9876543210;
    }
    else
    {
        goal = to_string(num).length() - 1;
        backTracking(9, 1);
        goal++;
        for (int o = 1; o <= 9; o++)
        {
            backTracking(o, 1);
        }
        goal++;
        backTracking(1, 1);
        cout << answerNum;
    }
}