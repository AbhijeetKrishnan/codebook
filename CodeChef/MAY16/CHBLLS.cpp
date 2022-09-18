#include <bits/stdc++.h>

using namespace std;

int main() {
	int wt;
	printf("1\n3 1 2 2\n3 3 4 4\n");
	fflush(stdout);
	scanf("%d", &wt);
	if (wt < 0) {
		if (wt == -2) {
			printf("2\n4\n");
			exit(0);
		}
		else {
			printf("2\n3\n");
			exit(0);
		}
	}
	else if (wt == 0) {
		printf("2\n5\n");
		exit(0);
	}
	else {
		if (wt == 2) {
			printf("2\n2\n");
			exit(0);
		}
		else {
			printf("2\n1\n");
			exit(0);
		}
	}
	return 0;
}