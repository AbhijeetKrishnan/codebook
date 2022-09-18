#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int a[n];
        for (long long int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long int count = 0;
        long long int curr_count = 1;
        for (long long int i = 1; i < n; i++)
        {
            if (a[i] >= a[i - 1])
            {
                ++curr_count;
            }
            else
            {
                count += (curr_count * (curr_count + 1)) / 2;
                curr_count = 1;
            }
        }
        count += (curr_count * (curr_count + 1)) / 2;
        cout << count << endl;
    }
    return 0;
}