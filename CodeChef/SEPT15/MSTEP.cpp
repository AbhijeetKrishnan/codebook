#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, pair<int, int>>> v;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int hold;
                cin >> hold;
                v.push_back(make_pair(hold, make_pair(i, j)));
            }
        }
        sort(v.begin(), v.end());
        long long int steps = 0;
        for (auto i = v.begin() + 1; i != v.end(); i++)
        {
            steps += abs((*i).second.first - (*(i - 1)).second.first) + abs((*i).second.second - (*(i - 1)).second.second);
        }
        cout << steps << endl;
    }
    return 0;
}