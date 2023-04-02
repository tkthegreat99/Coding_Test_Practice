#include<stdio.h>
#pragma warning(disable: 4996)

int main(void) {

	
	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = n-i-1; j > 0; j--) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		
		
		if (i != n - 1) {
			printf("\n");
		}
	}


	
	
}