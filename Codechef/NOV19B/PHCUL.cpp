#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const double dist(pair<int, int>& u, pair<int, int>& v) {
    int x1 = u.first, y1 = u.second;
    int x2 = v.first, y2 = v.second;
    long long int t1 = (1LL * x2 - x1) * (x2 - x1);
    long long int t2 = (1LL * y2 - y1) * (y2 - y1);
    return sqrt(t1 + t2);
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        pair<int, int> x;
        cin >> x.first >> x.second;
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> N(n), M(m), K(k);
        vector<int> min_n2k(n), min_m2k(m);
        for (auto &e: N) {
            cin >> e.first >> e.second;
        }
        for (auto &e: M) {
            cin >> e.first >> e.second;
        }
        for (auto &e: K) {
            cin >> e.first >> e.second;
        }
        for (int i = 0; i < n; i++) {
            double min_dist = dist(N[i], K[0]);
            for (int j = 0; j < k; j++) {
                double curr_dist = dist(N[i], K[j]);
                if (curr_dist < min_dist) {
                    min_dist = curr_dist;
                    min_n2k[i] = j;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            double min_dist = dist(M[i], K[0]);
            for (int j = 0; j < k; j++) {
                double curr_dist = dist(M[i], K[j]);
                if (curr_dist < min_dist) {
                    min_dist = curr_dist;
                    min_m2k[i] = j;
                }
            }
        }
        double min_distance = dist(N[0], x) + dist(M[0], N[0]) + dist(K[0], M[0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                min_distance = min(min_distance, dist(N[i], x) + dist(M[j], N[i]) + dist(K[min_m2k[j]], M[j]));
                min_distance = min(min_distance, dist(M[j], x) + dist(N[i], M[j]) + dist(K[min_n2k[i]], N[i]));
            }
        }
        cout << setprecision(10) << fixed << min_distance << "\n";
    }
    return 0;
}