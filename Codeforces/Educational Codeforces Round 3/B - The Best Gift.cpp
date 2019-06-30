#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int genre[11] = {0};
    for (int i = 0; i < n; i++)
    {
        int hold;
        scanf("%d", &hold);
        genre[hold]++;
    }
    int total = 0;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i + 1; j <= 10; j++)
        {
            total += genre[i] * genre[j];
        }
    }
    printf("%d", total);
    return 0;
}
