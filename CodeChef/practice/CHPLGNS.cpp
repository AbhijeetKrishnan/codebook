#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            int max_x = -1000000000;
            for (int j = 0; j < m; j++)
            {
                int x, y;
                cin >> x >> y;
                if (x > max_x)
                    max_x = x;
            }
            v.push_back(make_pair(max_x, i));
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[v[i].second] = i;
        }
        for (int i : ans)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}