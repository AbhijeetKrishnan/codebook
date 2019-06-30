#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        int hold;
        cin >> hold;
        v.push_back(make_pair(hold, i));
    }
    sort(v.begin(), v.end());

    long long int total = 0;
    for (int i = 1; i < n; i++)
    {
        total += abs(v[i].second - v[i-1].second);
    }
    cout << total << '\n';
    return 0;
}
