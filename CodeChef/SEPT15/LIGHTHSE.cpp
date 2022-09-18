#include <bits/stdc++.h>

using namespace std;

struct point
{
    int i;
    int x;
    int y;
    point()
    {
        i = 0;
        x = 0;
        y = 0;
    }
    point(int index, int x_coord, int y_coord)
    {
        i = index;
        x = x_coord;
        y = y_coord;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<point> v;
        /* Getting input */
        for (int i = 1; i <= n; i++)
        {
            int hold_x, hold_y;
            cin >> hold_x >> hold_y;
            v.push_back(point(i, hold_x, hold_y));
        }

        /* Finding ranges */
        int max_x, min_x;
        max_x = min_x = (*v.begin()).x;
        for(auto itr = v.begin() + 1; itr != v.end(); itr++)
        {
            if ((*itr).x > max_x) max_x = (*itr).x;
            if ((*itr).x < min_x) min_x = (*itr).x;
        }
        /* Getting topmost left and right */
        point top_left, top_right;
        top_left = top_right = *(v.begin());
        for (auto itr = v.begin() + 1; itr != v.end(); itr++)
        {
            if (((*itr).y > top_left.y) || (((*itr).y == top_left.y) && ((*itr).x < top_left.x))) top_left = *itr;
            if (((*itr).y > top_right.y) || (((*itr).y == top_right.y) && ((*itr).x > top_right.x))) top_right = *itr;
        }
        /* Getting bottommost left and right */
        point bot_left, bot_right;
        bot_left = bot_right = *(v.begin());
        for (auto itr = v.begin() + 1; itr != v.end(); itr++)
        {
            if (((*itr).y < bot_left.y) || (((*itr).y == bot_left.y) && ((*itr).x < bot_left.x))) bot_left = *itr;
            if (((*itr).y < bot_right.y) || (((*itr).y == bot_right.y) && ((*itr).x > bot_right.x))) bot_right = *itr;
        }

        /* Print all extreme points */
        /*
        cout << "Top left: " << top_left.i << " " << top_left.x << " " << top_left.y << endl;
        cout << "Top right: " << top_right.i << " " << top_right.x << " " << top_right.y << endl;
        cout << "Bottom left: " << bot_left.i << " " << bot_left.x << " " << bot_left.y << endl;
        cout << "Bottom right: " << bot_right.i << " " << bot_right.x << " " << bot_right.y << endl;
        */

        /* Check if extreme points lie on corner */
        if (top_left.x == min_x)
        {
            cout << "1" << endl;
            cout << top_left.i << " " << "SE" << endl;
        }
        else if (top_right.x == max_x)
        {
            cout << "1" << endl;
            cout << top_right.i << " " << "SW" << endl;
        }
        else if (bot_left.x == min_x)
        {
            cout << "1" << endl;
            cout << bot_left.i << " " << "NE" << endl;
        }
        else if (bot_right.x == max_x)
        {
            cout << "1" << endl;
            cout << bot_right.i << " " << "NW" << endl;
        }
        else
        {
            if (top_left.x <= bot_right.x)
            {
                cout << "2" << endl;
                cout << top_left.i << " " << "SE" << endl;
                cout << bot_right.i << " " << "NW" << endl;
            }
            else
            {
                cout << "2" << endl;
                cout << top_left.i << " " << "SW" << endl;
                cout << bot_right.i << " " << "NE" << endl;
            }
        }
    }
    return 0;
}