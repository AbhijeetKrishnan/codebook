#include<stdio.h>

int main()
{
    int T;
    int x, y;
    scanf("%d",&T);
    while(T>0)
    {
        int is_on_path = 0;
        scanf("%d %d",&x,&y);
        if(x==0&&y==0)
        {
            is_on_path = 1;
        }
        if(x>0)
        {
            if(x%2==0)
            {
                is_on_path = 0;
            }
            else
            {
                if((y>=(-(x-1)))&&(y<=(x+1)))
                {
                    is_on_path = 1;
                }
                else
                {
                    is_on_path = 0;
                }
            }
        }
        else
        {
            if((-x)%2!=0)
            {
                is_on_path = 0;
            }
            else
            {
                if((y>=x)&&(y<=(-x)))
                {
                    is_on_path = 1;
                }
                else
                {
                    is_on_path = 0;
                }
            }
        }
        if(is_on_path==0)
        {
            if(y>0)
            {
                if(y%2!=0)
                {
                    is_on_path = 0;
                }
                else
                {
                    if((x<=(y-1))&&(x>=(-y)))
                    {
                        is_on_path = 1;
                    }
                    else
                    {
                        is_on_path = 0;
                    }
                }
            }
            else
            {
                if((-y)%2!=0)
                {
                    is_on_path = 0;
                }
                else
                {
                    if((x>=y)&&(x<=((-y)+1)))
                    {
                        is_on_path = 1;
                    }
                    else
                    {
                        is_on_path = 0;
                    }
                }
            }
        }
        if(is_on_path==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        T -= 1;
    }
}