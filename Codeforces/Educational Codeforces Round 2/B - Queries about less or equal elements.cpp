#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bin_search(const vector<int> &v, const int &k)
{
    int lo = 0, hi = v.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] <= k)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int hold;
        cin >> hold;
        a.push_back(hold);
    }
    for (int i = 0; i < m; i++)
    {
        int hold;
        cin >> hold;
        b.push_back(hold);
    }
    sort(a.begin(), a.end());
    for (int i : b)
    {
        cout << bin_search(a, i) << ' ';
    }
    return 0;
}
