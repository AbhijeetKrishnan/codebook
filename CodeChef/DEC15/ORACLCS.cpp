#include <iostream>
#include <vector>

using namespace std;

struct word
{
    int a_count, b_count;
    word(string s)
    {
        a_count = 0;
        b_count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
                a_count++;
            else
                b_count++;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<word> w;
        cin >> n;
        while (n--)
        {
            string hold;
            cin >> hold;
            w.push_back(word(hold));
        }
        int min_a = (*w.begin()).a_count, min_b = (*w.begin()).b_count;
        for (auto itr = w.begin() + 1; itr != w.end(); itr++)
        {
            if ((*itr).a_count < min_a)
                min_a = (*itr).a_count;
            if ((*itr).b_count < min_b)
                min_b = (*itr).b_count;
        }
        cout << min(min_a, min_b) << '\n';
    }
    return 0;
}