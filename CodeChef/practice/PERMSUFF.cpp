#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> perm;
        for (int i = 0; i < n; i++)
        {
            int hold;
            cin >> hold;
            perm.push_back(hold);
        }
        vector<pair<int, int>> range, merged_range;
        for (int i = 0; i < m; i++)
        {
            int lb, rb;
            cin >> lb >> rb;
            range.push_back(make_pair(lb, 1));
            range.push_back(make_pair(rb, -1));
        }
        sort(range.begin(), range.end(), cmp);
        int balance = 0, lb, rb;
        for (auto i : range)
        {
            balance += i.second;
            if (balance == 1 && i.second == 1)
                lb = i.first;
            if (balance == 0)
            {
                rb = i.first;
                merged_range.push_back(make_pair(lb, rb));
            }
        }
        for (auto i : merged_range)
        {
            sort(perm.begin() + i.first - 1, perm.begin() + i.second);
        }
        bool is_possible = true;
        for (int i = 0; is_possible && i < n; i++)
        {
            if (i + 1 != perm[i])
                is_possible = false;
        }
        if (is_possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}