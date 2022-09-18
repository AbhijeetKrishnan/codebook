#include <stdio.h>

int main()
{
    int T;
    int N;
    int i, j;
    int num_of_inv, num_of_loc_inv;
    scanf("%d", &T);
    while(T--)
    {
        num_of_inv = 0;
        num_of_loc_inv = 0;
        scanf("%d", &N);
        int A[N];
        for (i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (i = 0; i < N - 1; i++)
        {
            j = i + 1;
            if(A[i] > A[j])
            {
                num_of_loc_inv += 1;
            }
            for ( ; j < N; j++)
            {
                if(A[i] > A[j])
                {
                    num_of_inv += 1;
                }
            }
        }
        if (num_of_inv == num_of_loc_inv)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}