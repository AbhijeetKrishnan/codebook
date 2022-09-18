#include <stdio.h>
int main()
{
    int t;
    int x; //page length of desired poetry
    int y; //pages left in notebook
    int k; //rubles left
    int n; //number of notebooks
    int nb_pages, nb_price;
    int i;
    int flag;
    scanf("%d", &t);
    while (t--)
    {
        flag = 0;
        scanf("%d %d %d %d", &x, &y, &k, &n);
        x = x - y;
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &nb_pages, &nb_price);
            if ((nb_pages >= x) && (nb_price <= k))
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("UnluckyChef\n");
        }
        else
        {
            printf("LuckyChef\n");
        }
    }
    return 0;
}