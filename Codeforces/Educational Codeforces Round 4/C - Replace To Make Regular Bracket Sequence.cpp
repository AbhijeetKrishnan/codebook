#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> s;
    int swaps = 0;
    bool is_valid = true;
    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '<' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == '>' || c == ']')
        {
            if (s.empty())
            {
                is_valid = false;
            }
            else
            {
                char top = s.top();
                s.pop();
                if (top != c - 1 && top != c - 2)
                    swaps++;
            }
        }
    }
    if (!s.empty())
        is_valid = false;

    if (is_valid)
    {
        cout << swaps << '\n';
    }
    else
    {
        cout << "Impossible\n";
    }
    return 0;
}
