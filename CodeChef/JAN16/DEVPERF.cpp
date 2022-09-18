#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string hold;
            cin >> hold;
            v.push_back(hold);
        }
        int min_x = n-1, max_x = 0, min_y = m-1, max_y = 0;
        bool is_inhabited = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '*')
                {
                    is_inhabited = true;
                    if (i < min_x)
                        min_x = i;
                    if (i > max_x)
                        max_x = i;
                    if (j < min_y)
                        min_y = j;
                    if (j > max_y)
                        max_y = j;
                }
            }
        }
        int ans;
        if (is_inhabited)
            ans = max(max_x - min_x + 1, max_y - min_y + 1) / 2 + 1;
        else
            ans = 0;
        cout << ans << '\n';
    }
    return 0;
}