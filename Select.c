#include<stdio.h>

void main() {
	int size = 0;
	printf("Enter the size of the array:");
	scanf("%d", &size);
	int array[size];
	printf("Enter array elements:");
	for (int k = 0; k < size; k++) {
		scanf("%d", &array[k]);
	} 
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] < array[j]) {
				int min = array[i];
				array[i] = array[j];
				array[j] = min;
			}
		}
	}
	printf("Sorted array is:");
	for (int l = 0; l < size; l++) {
		printf("%d\t", array[l]);
	}
}
