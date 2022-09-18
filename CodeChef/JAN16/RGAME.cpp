#include <iostream>
#include <vector>

using namespace std;
typedef long long int lli;
const int M = 1000000000 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<lli> v(n+1);
        for (int i = 0; i <= n; i++)
        {
            cin >> v[i];
        }

        lli ans;
        if (n == 1)
        {
            ans = (((v[0] * v[1]) % M) * 2) % M;
        }
        else if (n == 2)
        {
            ans = (((((v[0] * v[1]) % M) * 4) % M) + ((((v[2] * v[1]) % M) * 2) % M) + ((((v[0] * v[2]) % M) * 2) % M)) % M;
        }
        else
        {
            lli curr_pow = 2;
            lli curr_sum = (((v[0] + v[1]) % M) * 2) % M;
            ans = (((((v[0] * v[1]) % M) * 4) % M) + ((((v[2] * v[1]) % M) * 2) % M) + ((((v[0] * v[2]) % M) * 2) % M)) % M;
            for (int i = 3; i <= n; i++)
            {
                curr_pow = (curr_pow * 2) % M;
                curr_sum = (curr_sum + ((curr_pow * v[i-1]) % M)) % M;
                ans = (((2 * ans) % M) + ((v[i] * curr_sum) % M)) % M;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}