#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string num;

    bool has_zero = false, found_non_beautiful = false;
    long long int num_zeroes = 0;
    string non_beautiful_num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num[0] == '0' && num[1] == '\0')
        {
            has_zero = true;
        }
        else if (found_non_beautiful)
        {
            num_zeroes += num.size() - 1;
        }
        else
        {
            if (num[0] == '1')
            {
                bool is_beautiful_num = true;
                int i = 1;
                int tmp_num_zeroes = 0;
                while (is_beautiful_num && num[i] != '\0')
                {
                    if (num[i] != '0')
                        is_beautiful_num = false;
                    else
                        tmp_num_zeroes++;
                    i++;
                }
                if (!is_beautiful_num)
                {
                    non_beautiful_num = num;
                    found_non_beautiful = true;
                }
                else
                    num_zeroes += tmp_num_zeroes;
            }
            else
            {
                non_beautiful_num = num;
                found_non_beautiful = true;
            }
        }
    }
    if (has_zero)
        cout << "0\n";
    else if (!found_non_beautiful)
    {
        cout << "1";
        for (int i = 0; i < num_zeroes; i++)
        {
            cout << "0";
        }
        cout << '\n';
    }
    else
    {
        cout << non_beautiful_num;
        for (int i = 0; i < num_zeroes; i++)
        {
            cout << "0";
        }
        cout << '\n';
    }
    return 0;
}
