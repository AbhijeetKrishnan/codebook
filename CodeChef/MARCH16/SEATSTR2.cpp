#include <iostream>
#include <vector>

using namespace std;
typedef long long int lli;

const long long int M = 1e9 + 7;
const long long int N = 1e5 + 1;
vector<long long int> fact(N);

// To compute x^y under modulo m
long long int power(long long int x, unsigned long long int y, unsigned long long int m)
{
    if (y == 0)
        return 1;
    long long int p = power(x, y/2, m) % m;
    p = (1LL * p * p) % m;

    return (y % 2 == 0) ? p : (1LL * x * p) % m;
}

long long int modInverse(long long int a, long long int m)
{
    return power(a, m-2, m);
}

long long int nCr(unsigned long long int n, unsigned long long int r) {
    if (n < r)
        return 0;
    return ((((lli)fact[n] * modInverse(fact[r], M)) % M) * modInverse(fact[n - r], M)) % M;
}

    int main() {
    fact[0] = 1;
    for (long long int i = 1; i <= N; ++i) {
        fact[i] = ((lli)i * fact[i - 1]) % M;
    }
    long long int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long int n = s.size();
        vector<long long int> freq(26, 0);
        for (char c : s) {
            ++freq[c - 'a'];
        }
        long long int num_perm = fact[n];
        for (long long int f : freq) {
            num_perm = ((lli)num_perm * modInverse(fact[f], M)) % M;
        }
        long long int fC2 = 0, fC3 = 0, fC4 = 0;
        for (long long int i = 0; i < 26; ++i) {
            fC2 = (fC2 + nCr(freq[i], 2)) % M;
            fC3 = (fC3 + nCr(freq[i], 3)) % M;
            fC4 = (fC4 + nCr(freq[i], 4)) % M;
        }
        long long int fC2fC1 = 0, fC3fC1 = 0, fC2fC2 = 0;
        for (long long int i = 0; i < 26; ++i) {
            for (long long int j = 0; j < 26; ++j) {
                if (i != j) {
                    fC2fC1 = (fC2fC1 + ((lli)nCr(freq[i], 2) * nCr(freq[j], 1)) % M) % M;
                    fC3fC1 = (fC3fC1 + ((lli)nCr(freq[i], 3) * nCr(freq[j], 1)) % M) % M;
                    fC2fC2 = (fC2fC2 + ((lli)nCr(freq[i], 2) * nCr(freq[j], 2)) % M) % M;
                }
            }
        }
        fC2fC2 = (1LL * fC2fC2 * modInverse(2, M)) % M;
        long long int fC2fC1fC1 = 0;
        for (long long int i = 0; i < 26; ++i) {
            for (long long int j = 0; j < 26; ++j) {
                for (long long int k = 0; k < 26; ++k) {
                    if (i != j && j != k && i != k) {
                        fC2fC1fC1 = (fC2fC1fC1 + (((((lli)nCr(freq[i], 2) * nCr(freq[j], 1)) % M) * nCr(freq[k], 1)) % M)) % M;
                    }
                }
            }
        }
        fC2fC1fC1 = ((lli)fC2fC1fC1 * modInverse(2, M)) % M;
        long long int one_swap = (nCr(n, 2) - fC2 + M) % M;
        long long int one_point_five_swap = (((nCr(n, 3) - ((fC2fC1 + fC3) % M) + M) % M) * 2LL) % M;
        long long int two_swap = (((((nCr(n, 4) - ((fC4 + fC3fC1 + fC2fC2 + fC2fC1fC1) % M) + M) % M) * 3LL) % M) + ((fC2fC1fC1 * 2LL) % M) + fC2fC2) % M;
        long long int ans = ((lli)num_perm * (num_perm - 1)) % M;
        long long int similar_pairs = ((lli)((one_swap + one_point_five_swap + two_swap) % M) * num_perm) % M;
        ans = (ans - similar_pairs + M) % M;
        //cout << one_swap << " " << one_point_five_swap << " " << two_swap << '\n';
        cout << ans << '\n';
    }
    return 0;
}