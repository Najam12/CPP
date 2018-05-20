/*
 Author: Najam Rizvi
 Date: May 17th 
 Purpose: Demonstrate some basic testing concepts
 University of Guelph, 2018.
 CIS*2520 (DE) S18
*/

#include <stdlib.h>
#include <stdio.h>
#include "dlinkedADT.h"


Node *initializeNode(void *data){

	Node *newnode = malloc(sizeof(Node));

	newnode->data = (void*)data;
	newnode->next = NULL;
	newnode->previous = NULL;

return newnode;

}


List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){

	List * listnew = malloc (sizeof(List)); 

	listnew->head = NULL;

	printFunction(listnew);
	
	listnew->deleteData = *deleteFunction ;
	
	listnew->compare = *compareFunction;

return listnew;
}

void deleteList (List *list){

	if ( list == NULL){
		return ;
	}

	while (list -> head != NULL){
		Node *current = list->head;
		
		list->head = (Node*)list->head-> next;

		current -> next = NULL;
		list->head-> previous = NULL;
		
		current->data=NULL;
		free (current);
		
	}
	
}

void insertBack(List *list, void *toBeAdded){

	if(list==NULL)
		{
			return;
		}

	Node *newnode = initializeNode((void*)toBeAdded);

	if ( list-> head->data == NULL){
		
		list-> head = newnode;
		return;
	}

	Node * temp = list->head; 
	while ( temp -> next != NULL){

		temp = temp -> next;
	}

	temp -> next = newnode;
	newnode -> previous = temp;
}

void insertFront (List *list, void* toBeAdded){

	if (list == NULL){

		return;
	}

	Node * newnode = initializeNode (toBeAdded);

	if (list -> head -> data == NULL){
		list -> head = (Node*) newnode;
		return;
	}

	newnode -> next = (Node*) (list -> head);
	list -> head -> previous = (Node*) newnode;
	list -> head = newnode;

}


/*
Code unedited


void *getFromFront(List *list){

	if( list == NULL|| list -> head -> data == NULL){

		return NULL;
	}

	return list ->head -> data; 

}

void *getFromBack (List *list){

	if (list == NULL || list -> head -> data){

		return NULL;
	}

	Node * prev = list -> head;
	Node * curr = node -> next -> head; // ask brother

	while (curr != NULL){

		prev = curr;
		curr = curr -> next;
	}

	return prev;
}

int deleteDataFromList(List *list, void *toBeDeleted){

	if(NULL == NULL || list -> head -> data ||toBeDeleted == NULL){

		return;
	}

	Node *temp = list -> head;

	while(temp != NULL){

		if (temp -> data == toBeDeleted){
			
			if (temp == list -> head){
				list -> head = temp -> next;

				if (){
				

				}

			}
	
		}
	}

}

