#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int hold;
            cin >> hold;
            a.push_back(hold);
        }
        int count = 0;
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int sum = 0, prod = 1;
                for (int j = i; j < i + len; j++)
                {
                    sum += a[j];
                    prod *= a[j];
                    //cout << a[j] << ' ';
                }
                //cout << '\n';
                if (sum == prod)
                {
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}