#ifndef LINKD_H_
#define LINKD_H_

struct node{
	int val;
	struct node* next;
};

void addNode(struct node* *iterator, int num);
void killList(struct node* *iterator, struct node* *current);
void pop(struct node* *head, struct node* *iterator);

#endif //refers to LINKD_H_
