#include "linkd.h"
#include <stdlib.h>
#include <stdio.h>

//remember that when passing by reference to a pointer
//you need that extra * to indicate this to the compiler
void addNode(struct node* *iterator, int num){
	//move cursor to the end
	while((*iterator)->next != NULL)
		*iterator = (*iterator)->next;
	//add the num of nodes to list
	for(int i = 0;i < num; i++){
		//move th enode forward and allocate new
		//memory for the new node
		(*iterator)->next = malloc(sizeof(struct node));
		*iterator = (*iterator)->next;
		(*iterator)->next = NULL;
	}
}

void killList(struct node* *iterator, struct node* *current){
	*iterator = *current;
	while((*current)->next != NULL){
		//free the current node and
		//move on to the next node
		*iterator = (*iterator)->next;
		free(*current);
		*current = *iterator;
		printf("Freed!\n"); //take this out in the end
	}
	//then free the final node not dealt with in the loop
	free(*current);
}

void pop(struct node* *head, struct node* *iterator){
	//use a temp variable to find the end of the list
	//and free that last node in memory
	//I will count and print out the length
	int count = 0;

	struct node* temp;
	temp = *head;
	*iterator = *head;
	//offset temp so it's staggered with iterator
	temp = temp->next;
	
	while(temp->next != NULL){
		temp = temp->next;
		*iterator = (*iterator)->next;
		count++;
	}
	free(temp);
	(*iterator)->next = NULL;
	
	printf("Length of list: %d\n", count);
}

