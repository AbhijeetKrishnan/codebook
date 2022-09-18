#include <iostream>
     
    using namespace std;
     
    int main() {
    	int jc, sc, m;
    	cin >> jc >> sc >> m;
    	m -= jc;
    	int num_socks = m / sc;
    	if (num_socks & 1)
    		cout << "Unlucky Chef";
    	else
    		 cout << "Lucky Chef";
    	return 0;
    }