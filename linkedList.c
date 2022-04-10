#include<stdio.h>
#include<stdlib.h>

typedef struct Node * lstptr;

struct Node {
	int data;
	lstptr link;
};

lstptr first = NULL;

lstptr getNode() {
	lstptr new = (lstptr) malloc (sizeof(struct Node));
	return new;
}

void display() {
	lstptr temp = first;
	if (first == NULL) {
		printf("List is Empty\n");
	} else {
		while (temp->link != NULL) {
			printf("%d-->",temp->data);
			temp = temp->link;
		}
		printf("%d\n",temp->data);
	}
}

void insertBegin(int element) {
	lstptr new = getNode();
	new->link = NULL;
	new->data = element;
	if (first != NULL) {
		new->link  =  first;
	}
	first = new;
}

void insertEnd(int element) {
	lstptr temp = first;
	lstptr new = getNode();
	new->link = NULL;
	new->data = element;
	if (first == NULL) {
		first = new;
	} else {
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = new;
	}
}

void deleteBegin() {
	lstptr temp = first;
	if (first == NULL) {
		printf("List is Empty\n");
	} else {
		first = first->link;
		free(temp);
	}
}

void deleteEnd() {
	if (first == NULL) {
		printf("List is Empty\n");
		return;
	} else {
		lstptr temp = first;
		if (temp->link == NULL) {
			first = NULL;
			free(temp);
		} else {
			lstptr prev = first;
			while (temp->link != NULL) {
				prev = temp;
				temp = temp->link;
			}
			prev->link = NULL;
			free(temp);
		}

	}
}

void delSpec(int locationE) {
	lstptr temp = first;
	lstptr prev;
	if (first == NULL) {
		printf("List is Empty\n");
		return;
	} else if (temp->data == locationE) {
		first = first->link;
		free(temp);
	} else {
		while (temp->link != NULL) {
			prev = temp;
			temp = temp->link;
			if (temp->data == locationE) {
				prev->link = temp->link;
				free(temp);
				return;
			}
		}
		printf("This Element Not Exists\n");
	}
}

void main() {
	int choice;int option = 1;int element = 0;int locationE = 0;
	while (option) {
		printf("Menu\n1.Insert Begin\n2.Insert End\n3.Delete Begin\n4.Delete End\n5.Delete Specific Location\n6.Display\n7.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &choice);
		switch (choice) {
			case 1 :
				printf("Enter the element to be inserted:");
				scanf("%d", &element);
				insertBegin(element);
				break;
			case 2 :
				printf("Enter the element to be inserted:");
				scanf("%d", &element);
				insertEnd(element);
				break;
			case 3 :
				deleteBegin();
				break;
			case 4 :
				deleteEnd();
				break;
			case 5 :
				if (first != NULL) {
				printf("Enter the element to be deleted:");
				scanf("%d", &locationE);
				delSpec(locationE);} else {
					printf("List is Empty\n");
				}
				break;
			case 6 :
				display();
				break;
			case 7 : exit(0);
			default: printf("Enter correct choice:");
				 break;	
		}
		printf("Do you want to continue:");
		scanf("%d", &option);
	}
}
