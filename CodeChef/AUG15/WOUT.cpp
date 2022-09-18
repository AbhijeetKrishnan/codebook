#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, h;
        cin >> n >> h;
        int *store = new int[n];

        for (int i = 0; i < n; i++)
        {
            store[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int hold_l, hold_h;
            cin >> hold_l >> hold_h;

            store[hold_l]++;
            if (hold_h != (n - 1))
                store[hold_h + 1]--;
        }
        for (int i = 1; i < n; i++)
        {
            store[i] += store[i - 1];
        }

        /*
        for(int i = 0; i < n; i++) cout << store[i] << " ";
        cout << endl;
        */

        long long int curr_sum = 0;
        for (int i = 0; i < h; i++) curr_sum += store[i];
        long long int max_sum = curr_sum;
        for (int i = h; i < n; i++)
        {
            curr_sum += (store[i] - store[i - h]);
            if (curr_sum > max_sum)
                max_sum = curr_sum;
        }
        cout << (long long int)n * h - max_sum << endl;
    }
    return 0;
}