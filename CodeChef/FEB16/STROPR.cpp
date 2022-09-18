#include <cstdio>
#include <vector>

using namespace std;
typedef long long int lli;

const int M = 1e9 + 7;

int gcdExtended(int, int, int*, int*);

int modinv(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    int res = (x%m + m) % m;
    return res;
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        lli m;
        scanf("%d %d %lld", &n, &x, &m);
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            lli hold;
            scanf("%lld", &hold);
            v[i] = hold % M;
        }
        int ans = v[x-1], curr_coeff = 1;
        m = m % M;
        for (int i = x - 2, j = 1; i >= 0; i--, j++) {
            curr_coeff = (curr_coeff * (((m + j - 1) * modinv(j, M)) % M)) % M;
            ans = (ans + ((lli)curr_coeff * v[i]) % M) % M;
        }
        printf("%d\n", ans);
    }
    return 0;
}