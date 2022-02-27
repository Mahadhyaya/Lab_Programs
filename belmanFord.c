#include<stdio.h>

int array[20][20];
int n = 0;

int min(int, int);

void function() {
	int count = 0;
	for (int k = 0; k < n; k++) {
		count++;
		for (int r = 0; r < n; r++) {
			count++;
			for (int l = 0; l < n; l++) {
				count++;
				array[r][l] = min(array[r][l], array[r][k] + array[k][l]);
			}
		}
	}
	printf("Total:%d", count);
}

int min(int a, int b) {
	return a > b ? b : a;
}


int main() {
	printf("Enter number of nodes:");
	scanf("%d", &n);
	printf("Enter array elements:");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &array[i][j]);
			if (array[i][j] == 0) {
				array[i][j] = 999;
			}
			if (i == j) {
				array[i][j] = 0;
			}	
		}
	}
	function();
	printf("The vector table:\n");
	for (int k = 0; k < n; k++) {
		for (int l = 0; l < n; l++) {
			printf("%2d", array[k][l]);
		}
		printf("\n");
	}
	return 0;
}
