#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000000 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int hold;
            cin >> hold;
            v.push_back(hold);
        }
        sort(v.begin(), v.end());

        long long int max_sum = 0, min_sum = 0;
        for (int i = 0, j = n - 1; i < n - 1 && j > 0; i++, j--)
        {
            min_sum += v[i];
            min_sum <<= 1;
            min_sum %= MOD;

            max_sum += v[j];
            max_sum <<= 1;
            max_sum %= MOD;
        }
        max_sum += v[0];
        min_sum += v[n-1];
        max_sum %= MOD;
        min_sum %= MOD;

        cout << (max_sum - min_sum + MOD) % MOD << '\n';
    }
    return 0;
}