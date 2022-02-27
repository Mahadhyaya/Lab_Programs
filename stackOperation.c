#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 4
int top = -1;
int stack[30];
void push(int element) {
	if (top == MAXSIZE - 1) {
		printf("Stack full");
		exit(0);
	}
	stack[++top] = element;
}

int pop() {
	if (top == -1) {
		printf("Stack empty");
		exit(0);
	}
	return stack[top--];
}

void display() {
	if (top != -1) {
		printf("Stack elements are:");
		for (int i = 0; i <= top; i++) {
			printf("%d", stack[i]);
		}
	} else {
		printf("No elements in the stack");
	}
}

void main() {
	int choice = 0;
	int elemen = 0;
	while (1) {
	printf("MENU:\n1.push\n2.pop\n3.display\n4.exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice) {
		case 1 :
			printf("Enter elements to be pushed:");
			scanf("%d", &elemen);
			push(elemen);
			break;
		case 2:
			printf("%d", pop());
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("wrong choice\n");
			break;
	} 
	} 
}
