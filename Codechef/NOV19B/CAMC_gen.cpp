#include <iostream>
#include <cstdlib>

using namespace std;

int rand_range(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int t = 1;
    cout << t << "\n";
    for (int test = 0; test < t; test++) {
        int n, m;
        n = rand_range(2, 10);
        m = rand_range(2, n);
        cout << n << " " << m << "\n";
        for (int i = 0; i < n; i++) {
            int a = rand_range(1, 20);
            cout << a << " ";
        }
        cout << "\n";
    }
    return 0;
}