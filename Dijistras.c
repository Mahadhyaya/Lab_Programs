#include<stdio.h>

int source, cost[10][10], number, d[10], p[10];

void dijistras() {
	int s[10];
	for (int i = 0; i < number; i++) {
		s[i] = 0;
		p[i] = source;
		d[i] = cost[source][i];		
	}
	s[source] = 1;

    for (int i = 1; i < number; i++) {
	int minimum = 99, u = -1;
	for (int j = 0; j < number; j++) {
		if (s[j] == 0) {
			if (d[j] < minimum) {
				minimum = d[j];
				u = j;	
			}			
		}		
	}
	if (u == -1) {
		return;		
	}
	s[u] = 1;
	for (int v = 0; v < number; v++) {
		if (s[v] == 0) {
			if (d[u] + cost[u][v] < d[v]) {
				d[v] = d[u] + cost[u][v];	
				p[v] = u;
			}
		}	
	}
    }
}

void shortestPath(int destination) {
	int i = destination;
	while (i != source) {
		printf("%d<--", i);
		i = p[i];	
	}
	printf("%d=%d", source, d[destination]);
}

void main() {
	printf("Enter the number of vertices:");
	scanf("%d", &number);
	printf("Enter cost adjacency matrix:");
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			scanf("%d", &cost[i][j]);
		}		
	}
	printf("The cost adjacency matrix is:\n");
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			printf("%d\t", cost[i][j]);
		}
		printf("\n");		
	}
	printf("Enter the source vertex:");
	scanf("%d", &source);
	dijistras();
	for (int r = 0; r < number; r++) {
		shortestPath(r);	
		printf("\n");
	}
}
