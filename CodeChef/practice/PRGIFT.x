#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int num_even = 0;
        for (int i = 0; i < n; i++)
        {
            int hold;
            cin >> hold;
            if (!(hold&1))
                num_even++;
        }
        if (num_even == n && k == 0)
            cout << "NO\n";
        else if (num_even >= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}