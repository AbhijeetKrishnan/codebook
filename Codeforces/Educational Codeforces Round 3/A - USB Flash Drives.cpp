#include <cstdio>
#include <vector>
#include <algorithm>

bool cmp(int a, int b)
{
    return a > b;
}

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int hold;
        scanf("%d", &hold);
        v.push_back(hold);
    }
    sort(v.begin(), v.end(), cmp);
    int total = 0, count = 0;
    int i = 0;
    while (total < m)
    {
        total += v[i];
        count++;
        i++;
    }
    printf("%d\n", count);
    return 0;
}
