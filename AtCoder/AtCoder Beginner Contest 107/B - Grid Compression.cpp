#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        bool white_row = true;
        for (int j = 0; j < w and white_row; ++j) {
            if (v[i][j] == '#') {
                white_row = false;
            }
        }
        if (white_row) {
            for (int j = 0; j < w; ++j) {
                if (v[i][j] == '.') {
                    v[i][j] = '-';
                }
            }
        }
    }
    for (int j = 0; j < w; ++j) {
        bool white_col = true;
        for (int i = 0; i < h and white_col; ++i) {
            if (v[i][j] == '#') {
                white_col = false;
            }
        }
        if (white_col) {
            for (int i = 0; i < h; ++i) {
                if (v[i][j] == '.') {
                    v[i][j] = '-';
                }
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        bool printed = false;
        for (int j = 0; j < w; ++j) {
            if (v[i][j] != '-') {
                cout << v[i][j];
                printed = true;
            }
        }
        if (printed)
            cout << "\n";
    }
    return 0;
}