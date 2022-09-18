#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
int rand_range(T a, T b) {
    return rand() % (b - a + 1) + a;
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n, m;
    n = rand_range<int>(1, 2);
    m = 3;
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        long long int p = rand_range<int>(1, 4);
        cout << p << " ";
    }
    return 0;
}