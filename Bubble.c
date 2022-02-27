#include<stdio.h>

void main() {
	int array[100];
	int size = 0;
	printf("Enter the size of the array:");
	scanf("%d", &size);
	printf("Enter array elements:");
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	for (int r = 0; r < size - 1; r++) {
		for (int j = 0; j < size - r - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				
			}
		}
	}
	printf("Sorted array is:");
	for (int j = 0; j < size; j++) {
		printf("%d\t", array[j]);
	}
}
