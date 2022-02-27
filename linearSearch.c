#include<stdio.h>
#include<stdlib.h>

int lSearch(int, int);
int array[30];
int n = 0;
void main() {
	int element = 0;
	printf("Enter the size of the array:");
	scanf("%d", &n);
	printf("Enter the array elements:");
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	printf("Enter the elements to be searched:");
	scanf("%d", &element);
	for (int j = 0; j < n; j++) {
		if (array[j] == element) {
			printf("The element found at %dth location", j);
			exit(0);
		}
	}
}

