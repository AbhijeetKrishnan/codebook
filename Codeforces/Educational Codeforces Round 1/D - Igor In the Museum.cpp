#include <iostream>
#include <vector>

using namespace std;

int _get_num_moves(vector<string> &v, vector<bool> moves, int x, int y)
{
    int count = 0;
    //cout << x << ' ' << y << '\n';
    if (v[x][y] != 'x')
    {
        if (v[x-1][y] == '*')
        {
            count++;
            moves[0] = false;
        }
        if (v[x+1][y] == '*')
        {
            count++;
            moves[1] = false;
        }
        if (v[x][y-1] == '*')
        {
            count++;
            moves[2] = false;
        }
        if (v[x][y+1] == '*')
        {
            count++;
            moves[3] = false;
        }
        v[x][y] = 'x';
        vector<bool> new_moves;
        if (moves[0])
        {
            new_moves = {true, false, true, true};
            count += _get_num_moves(v, new_moves, x-1, y);
        }
        if (moves[1])
        {
            new_moves = {false, true, true, true};
            count += _get_num_moves(v, new_moves, x+1, y);
        }
        if (moves[2])
        {
            new_moves = {true, true, true, false};
            count += _get_num_moves(v, new_moves, x, y-1);
        }
        if (moves[3])
        {
            new_moves = {true, true, false, true};
            count += _get_num_moves(v, new_moves, x, y+1);
        }
    }
    return count;
}

int get_num_moves(vector<string> v, int x, int y)
{
    vector<bool> moves = {true, true, true, true};
    return _get_num_moves(v, moves, x, y);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string hold;
        cin >> hold;
        v.push_back(hold);
    }
    vector<vector<int>> store;
    for (int i = 0; i < n; i++)
    {
        store.push_back({});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
                store[i].push_back(get_num_moves(v, i, j));
            else
                store[i].push_back(0);
        }
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << store[x-1][y-1] << '\n';
    }
    return 0;
}
