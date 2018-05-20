/*
@file dlinkedAPI.h
@author Najam Rizvi
@date May, 17, 2018
@brief File containing the function definitions of a doubly linked list
 */

#ifndef _dlist_API_
#define _dlist_API_

#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
	
	void *data;
	struct node * previous;
	struct node * next;
}Node;

typedef struct listhead{
	
	Node* head;
	Node* tail;
	void (*deleteData)(void *toBeDeleted);
    int (*compare)(const void *first,const void *second);
    void (*printData)(void *toBePrinted);
} List;

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

Node *initializeNode(void *data);

void insertFront(List *list, void *toBeAdded);

void insertBack(List *list, void *toBeAdded);

void deleteList(List *list);

void insertSorted(List *list, void *toBeAdded);

int deleteDataFromList(List *list, void *toBeDeleted);

void *getFromFront(List *list);

void *getFromBack(List *list);

void printForward(List *list);

void printBackwards(List *list);

#endif