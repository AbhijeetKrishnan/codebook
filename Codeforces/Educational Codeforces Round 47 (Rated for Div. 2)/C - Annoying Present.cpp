#include <bits/stdc++.h>

using namespace std;

long long sum_n(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    long double avg;
    int x, d;
    for (int j = 0; j < m; ++j) {
        cin >> x >> d;
        int i;
        if (d < 0) {
            i = n / 2 + (n % 2);
        }
        else {
            i = 1;
        }
        sum += (long long)n * x + d * (sum_n(i - 1) + sum_n(n - i));
    }
    avg = (long double)sum / n;
    printf("%.15Lf", avg);
    return 0;
}