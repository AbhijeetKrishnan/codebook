#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int n, k, m;
        cin >> n >> k >> m;
        vector<int> planned(n), completed(n);
        multiset<int> white, black;
        for (int i = 0; i < n; i++)
        {
            cin >> planned[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> completed[i];
        }
        for (int i = 0; i < k; i++)
        {
            int hold;
            cin >> hold;
            white.insert(hold);
        }
        for (int i = 0; i < m; i++)
        {
            int hold;
            cin >> hold;
            black.insert(hold);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto white_choice = white.upper_bound(planned[i] - completed[i]);
            if (white_choice != white.begin())
            {
                white_choice--;
            }
            else
            {
                white_choice = white.end();
            }
            auto black_choice = black.upper_bound(planned[i] - completed[i]);
            if (black_choice != black.begin())
            {
                black_choice--;
            }
            else
            {
                black_choice = black.end();
            }

            if (white_choice != white.end() && black_choice != black.end())
            {
                if (*white_choice > *black_choice)
                {
                    planned[i] -= *white_choice;
                    white.erase(white_choice);
                }
                else
                {
                    completed[i] += *black_choice;
                    black.erase(black_choice);
                }
            }
            else if (white_choice != white.end())
            {
                planned[i] -= *white_choice;
                white.erase(white_choice);
            }
            else if (black_choice != black.end())
            {
                completed[i] += *black_choice;
                black.erase(black_choice);
            }
            ans += planned[i] - completed[i];
        }
        cout << ans << '\n';
    }
    return 0;
}