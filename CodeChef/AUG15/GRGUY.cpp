#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string lane1, lane2;
        cin >> lane1;
        cin >> lane2;
        int jumps = 0;
        bool possible = true;
        int i = 0;
        while (lane1[i] == '.' && lane2[i] == '.')
        {
            i++;
        }
        if (lane1[i] == '#' && lane2[i] == '#')
        {
            possible = false;
        }
        else
        {
            int curr_lane;
            if (lane1[i] == '.')
            {
                curr_lane = 1;
            }
            else
            {
                curr_lane = 2;
            }
            while (possible && i < lane1.length() - 1)
            {
                if ((curr_lane == 1 && lane1[i + 1] == '.') || (curr_lane == 2 && lane2[i + 1] == '.')) i++;
                else if ((curr_lane == 1 && lane2[i + 1] == '.') || (curr_lane == 2 && lane1[i + 1] == '.'))
                {
                    jumps++;
                    curr_lane = (curr_lane == 1) ? 2 : 1;
                    i++;
                }
                else
                {
                    possible = false;
                }
            }
        }
        if (possible)
        {
            cout << "Yes" << endl;
            cout << jumps << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}