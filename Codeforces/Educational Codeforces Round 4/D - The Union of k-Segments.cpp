#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<int, char>> v;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        v.push_back(make_pair(start, '+'));
        v.push_back(make_pair(end, '-'));
    }
    sort(v.begin(), v.end());

    int count = 0;
    int first, second;
    for (auto p : v)
    {
        if (p.second == '+')
        {
            if (count == k - 1)
            {
                first = p.first;
            }
            count++;
        }
        else if (p.second == '-')
        {
            if (count == k)
            {
                second = p.first;
                ans.push_back(make_pair(first, second));
            }
            count--;
        }
    }
    printf("%d\n", ans.size());
    for (auto p : ans)
    {
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}
