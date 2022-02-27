#include<stdio.h>

int main() {
	int data[20];
	int rec[20];
	int p1, p2, p4;
	printf("Enter the message(Only in 1s and 0s):");
	scanf("%d%d%d%d", &data[0], &data[1], &data[2], &data[4]);
	data[3] = data[2] ^ data[1] ^ data[0];
	p4 = data[3];
	data[5] = data[0] ^ data[1] ^ data[4];
	p2 = data[5];
	data[6] = data[4] ^ data[2] ^ data[0];
	p1 = data[6];
	for (int j = 0; j < 7; j++) {
		printf("%d", data[j]);
	}
	printf("Enter the message to be compared:\n");
	int c = 0;
	int count = 0;
	for (int r = 0; r < 7; r++) {
		scanf("%d", &rec[r]);
	}
	for (int t = 0; t < 7; t++) {
		if (data[t] == rec[t]) {
			count++;
		} else {
			printf("Error in position:%d", t);
		}
	}
	if (count == 7) {
		printf("There is no error");
	}
	return 0;
}
