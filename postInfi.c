#include<stdio.h>
#include<string.h>
#include<ctype.h>

char postfix[20];
int top = -1;
char stack[20];
char op2;
char op1;
int l = 0;
void push(char c) {
	stack[++top] = c;
}

char pop() {
	return stack[top--];
}

void evaluation() {
	l = strlen(postfix);
	printf("The infix expression is:");
	for (int i = 0; i < l; i++) {
		/*if (posfix[i] == '+' || posfix[i] == '-' || posfix[i] == '*' || posfix[i] == '/') {
			op2 = pop();
			op1 = pop();
		} else {
			push(postfix[i]);
		}*/
		if (isalnum(postfix[i])) {
			push(postfix[i]);
		} else {
			op2 = pop();
			op1 = pop();
			printf("%c%c%c%c", '(', op1, postfix[i], op2, ')');
		}
	}
}

int main() {
	printf("Enter postfix expression:");
	scanf("%s",postfix);
	evaluation();
	return 0;	
}
