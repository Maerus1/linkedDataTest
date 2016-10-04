#include <stdio.h>
#include <stdlib.h>
#include "linkd.h"

int main(void){
	int num = 0;

	struct node* head = malloc(sizeof(struct node));	
	struct node* iterate;
	iterate = head;
	//call addNode to add a set number of nodes
	//after you ask for input of course :)
	printf("Please enter the number of nodes you want: ");
	scanf("%d", &num);
	addNode(&iterate, num);
	iterate = head;
	//add values
	for(int i = 0; i < num; i++){
		iterate->val = i;
		iterate = iterate->next;
		printf("Value: %d\n", i);
	}
	//I need to fix this pop method
	pop(&head, &iterate);
	//add more nodes
	addNode(&iterate, 3);
	pop(&head, &iterate);
	//then delete the whole list
	killList(&iterate,&head);
	return 0;
}
