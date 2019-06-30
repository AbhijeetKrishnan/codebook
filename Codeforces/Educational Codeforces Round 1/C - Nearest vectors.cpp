#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
const double PI = 3.14159265359;

bool cmp(pair<long double, int> a, pair<long double, int> b)
{
    return (a.first < b.first);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<long double, int>> vectors;
    for (int i = 1; i <= n; i++)
    {
        long double x, y;
        cin >> x >> y;
        vectors.push_back(make_pair(atan2(y, x), i));
        //cout << vectors[i-1].first << ' ';
    }
    cout << endl;
    sort(vectors.begin(), vectors.end(), cmp);
    double min_diff = abs(vectors[n-1].first - vectors[0].first);
    if (min_diff > PI) {
        min_diff -= PI;
    }
    int ind_a = vectors[n-1].second, ind_b = vectors[0].second;
    for (int i = 1; i < n; i++)
    {
        double val = abs(vectors[i].first - vectors[i-1].first);
        if (val > PI) {
            val -= PI;
        }
        if (val < min_diff)
        {
            min_diff = val;
            ind_a = vectors[i-1].second;
            ind_b = vectors[i].second;
        }
    }
    cout << ind_a << ' ' << ind_b;
    return 0;
}
