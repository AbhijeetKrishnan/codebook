#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    int n, m;
    int *jobs, *chef_jobs, *assistant_jobs;
    int i, k, l, tmp;
    int chef_jobs_count, assistant_jobs_count;
    scanf("%d", &t);
    while (t--)
    {
        k = 0;
        l = 0;
        chef_jobs_count = 0;
        assistant_jobs_count = 0;
        scanf("%d %d", &n, &m);
        jobs = (int*)malloc((n + 1) * sizeof(int));
        chef_jobs = (int*)malloc(n * sizeof(int));
        assistant_jobs = (int*)malloc(n * sizeof(int));
        for (i = 0; i <= n; i++)
        {
            jobs[i] = 1;
        }
        for (i = 0; i < m; i++)
        {
            scanf("%d", &tmp);
            jobs[tmp] = 0;
        }
        for (i = 1; i <= n; i++)
        {
            while ((jobs[i] != 1) && (i <= n))
            {
                i++;
            }
            if (i <= n)
            {
                chef_jobs[k++] = i;
                chef_jobs_count++;
                i++;
            }
            while ((jobs[i] != 1) && (i <= n))
            {
                i++;
            }
            if (i <= n)
            {
                assistant_jobs[l++] = i;
                assistant_jobs_count++;
            }
        }
        for (i = 0; i < chef_jobs_count; i++)
        {
            printf("%d ", chef_jobs[i]);
        }
        printf("\n");
        for (i = 0; i < assistant_jobs_count; i++)
        {
            printf("%d ", assistant_jobs[i]);
        }
        printf("\n");
    }
    return 0;
}