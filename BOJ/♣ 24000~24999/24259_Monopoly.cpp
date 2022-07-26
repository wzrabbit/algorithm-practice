#include <iostream>
#include <string>
using namespace std;

string find_reverse(int vertex, int edge, int input[][2])
{
    string answer = "";

    for (int i = 0; i <= edge; i++)
    {
        if (input[i][0] > input[i][1])
            answer += "1";
        else
            answer += "0";
    }

    return answer;
}
