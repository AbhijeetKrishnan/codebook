#include<bits/stdc++.h>
using namespace std;
char A[1001],B[1001];
int A_map[26],B_map[26];
int main()
{
    unsigned int T,A_len,B_len,flag,tmp;
    cin>>T;
    while(T--)
    {
        memset(A_map,0,4 * 26);
        memset(B_map,0,4 * 26);
        flag=0;
        cin>>A;
        cin>>B;
        A_len=strlen(A);
        B_len=strlen(B);
        for(int i=0;i<A_len;i++)
        {
            tmp=A[i];
            A_map[tmp-97]++;
        }
        for(int i=0;i<B_len;i++)
        {
            tmp=B[i];
            B_map[tmp-97]++;
        }
        for(int i=0;i<26 && flag==0;i++)
        {
            if(A_map[i]>0 && B_map[i]>0)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return(0);
}