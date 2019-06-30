#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int freq[26] = {0};
    vector<char> odd;
    for (char c : s)
    {
        freq[c - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i]&1)
        {
            odd.push_back('a' + i);
        }
    }
    int i = 0, j = odd.size() - 1;
    while (i < j)
    {
        freq[odd[i] - 'a']++;
        freq[odd[j] - 'a']--;
        i++;
        j--;
    }
    int odd_index = -1;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i]&1)
        {
            odd_index = i;
            break;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int count = 1; count <= freq[i] / 2; count++)
        {
            cout << (char)('a' + i);
        }
        freq[i] = (freq[i] / 2) + (freq[i] & 1);
    }
    if (odd_index != -1)
    {
        cout << (char)('a' + odd_index);
        freq[odd_index]--;
    }
    for (int i = 25; i >= 0; i--)
    {
        for (int count = 1; count <= freq[i]; count++)
        {
            cout << (char)('a' + i);
        }
    }
    return 0;
}
