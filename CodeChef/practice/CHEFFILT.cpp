#include <iostream>

using namespace std;

const int MOD = 1000000000 + 7;

int img2num(string s)
{
    int ret_val = 0;
    for (int i = 0; i < 10; i++)
    {
        ret_val <<= 1;
        if (s[i] == 'w')
            ret_val++;
    }
    return ret_val;
}

int filt2num(string s)
{
    int ret_val = 0;
    for (int i = 0; i < 10; i++)
    {
        ret_val <<= 1;
        if (s[i] == '+')
            ret_val++;
    }
    return ret_val;
}

int pow2withmod(int n)
{
    int ret_val = 1;
    long long int x = 2;
    for (int i = n; i != 0; i>>=1)
    {
        if (i&1)
            ret_val = ((ret_val % MOD) * (x % MOD)) % MOD;
        x = ((x % MOD) * (x % MOD)) % MOD;
    }
    return (int)(ret_val % MOD);
}

int memo[1025][1024];
int filters[1024];

int build(int i, int j)
{
    int ret_val;
    if (memo[i+1][j] != -1)
        ret_val = memo[i+1][j] % MOD;
    else if (i == -1)
        ret_val = memo[i+1][j] = (j == 0) ? 1 : 0;
    else if (i > -1 && filters[i] == 0)
        ret_val = memo[i+1][j] = build(i - 1, j) % MOD;
    else
        ret_val = memo[i+1][j] = ((((build(i - 1, j) % MOD) + (build(i - 1, j ^ i) % MOD)) % MOD) * ((long long int)pow2withmod(filters[i] - 1) % MOD)) % MOD;
    //cout << "f(" << i << "," << j << ")=" << ret_val << '\n';
    return ret_val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string img;
        cin >> img;
        int img_num = img2num(img);
        int n;
        cin >> n;
        for (int i = 0; i < 1024; i++)
        {
            filters[i] = 0;
        }
        for (int i = 0; i < 1025; i++)
        {
            for (int j = 0; j < 1024; j++)
            {
                memo[i][j] = -1;
            }
        }
        while (n--)
        {
            string hold_filt;
            cin >> hold_filt;
            int hold_filt_num = filt2num(hold_filt);
            filters[hold_filt_num]++;
        }
        cout << build(1023, img_num) % MOD << '\n';
    }
    return 0;
}