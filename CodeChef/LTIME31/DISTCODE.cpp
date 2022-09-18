#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        unordered_set<string> sub;
        int n = s.length();
        for (int i = 0; i < n - 1; i++)
        {
            sub.insert(s.substr(i, 2));
        }
        cout << sub.size() << '\n';
    }
    return 0;
}