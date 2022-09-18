#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
int rand_range(T a, T b) {
    return rand() % (b - a + 1) + a;
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n, k;
    n = rand_range<int>(1, 3);
    k = rand_range<int>(1, min(n * (n + 1) / 2, (int)1e5));
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
        int p = rand_range<int>(1, 10);
        cout << p << " ";
    }
    return 0;
}