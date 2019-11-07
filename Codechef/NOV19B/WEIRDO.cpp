#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++) {
        int l;
        scanf("%d", &l);
        vector<string> L(l);
        for (auto &s: L) {
            cin >> s;
        }
        vector<bool> isBob(l, false);
        int k_alice, k_bob = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < l; i++) {
            for (int j = 0; j + 1 < L[i].size(); j++) {
                if (vowels.find(L[i][j]) == vowels.end() and vowels.find(L[i][j + 1]) == vowels.end()) {
                    isBob[i] = true;
                    k_bob++;
                    break;
                }
            }
            if (not isBob[i]) {
                if (vowels.find(L[i][0]) == vowels.end() and vowels.find(L[i][L[i].size() - 1]) == vowels.end() and L[i].size() % 2 != 0) {
                    isBob[i] = true;
                    k_bob++;
                }
            }
        }
        k_alice = l - k_bob;

        vector<int> x_alice(26, 0), x_bob(26, 0), freq_alice(26, 0), freq_bob(26, 0);
        for (int i = 0; i < l; i++) {
            vector<bool> seen(26, false);
            vector<int> &x = isBob[i] ? x_bob : x_alice;
            vector<int> &freq = isBob[i] ? freq_bob : freq_alice;
            for (char c: L[i]) {
                freq[c - 'a']++;
                if (not seen[c - 'a']) {
                    x[c - 'a']++;
                    seen[c - 'a'] = true;
                }
            }
        }

        /*
        cout << "K_alice: " << k_alice << " K_bob: " << k_bob << "\n";
        cout << "X_alice: ";
        for (int x: x_alice) {
            if (x != 0) {
                cout << x << " ";
            }
        }
        cout << "\n";
        cout << "Freq_alice: ";
        for (int x: freq_alice) {
            if (x != 0) {
                cout << x << " ";
            }
        }
        cout << "\n";
        cout << "X_bob: ";
        for (int x: x_bob) {
            if (x != 0) {
                cout << x << " ";
            }
        }
        cout << "\n";
        cout << "Freq_bob: ";
        for (int x: freq_bob) {
            if (x != 0) {
                cout << x << " ";
            }
        }
        cout << "\n";
        */

        long double score = 0;
        for (int x: x_alice) {
            if (x != 0) {
                score += log(x);
            }
        }
        for (int x: x_bob) {
            if (x != 0) {
                score -= log(x);
            }
        }
        for (int freq: freq_alice) {
            if (freq != 0) {
                score -= k_alice * log(freq);
            }
        }
        for (int freq: freq_bob) {
            if (freq != 0) {
                score += k_bob * log(freq);
            }
        }
        if (score > log(1e7)) {
            printf("Infinity\n");
        }
        else {
            printf("%.10Lf\n", exp(score));
        }
    }
    return 0;
}