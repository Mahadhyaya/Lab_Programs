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
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (array[mid] < element) {
			start = mid + 1;
		} else if (array[mid] > element) {
			end = mid - 1;
		} else {
			printf("The element found at %dth position", mid);
			exit(0);
		}
	}
	printf("The element doesnot exists");
}
