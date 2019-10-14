#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

void printNodes();

typedef struct node{
	
  int size;
  int isEmpty;
}Node;


void printNodes(){

	Node * currentNode = (Node *) mydata;
	int x = 0;
	while(currentNode->size != NULL){

		printf("Node %d Size: %d isEmpty %d\n",x,currentNode->size,currentNode->isEmpty);
		x++;
		currentNode = (char *)currentNode + sizeof(Node) + currentNode->size;
	}


}


void* mymalloc(size_t size, char * file,int line){

	//gets first node from data
	Node * currentNode = (Node *) mydata;

	if(currentNode -> size == NULL){ //Might be in the header file? or before everything?

	    Node headNode;
	    headNode.isEmpty = 1;
	    headNode.size = sizeof(mydata) - sizeof(Node); //size of the rest of the data array
	    *currentNode = headNode;


  	}
	
	//Loops through each node
	while(currentNode->size != NULL){

		if(currentNode->isEmpty == 1 && currentNode->size == size){

		  	//Great nothing much is needed
		  	currentNode->isEmpty = 0;
		  	return ++currentNode;

	  	}

  		if(currentNode->isEmpty == 1 && currentNode->size > size){

	  		//A split is Needed

		  	//check if there is enough remaining
		  	if(currentNode->size - size <= sizeof(Node)){
		  		//no split

		  		currentNode->isEmpty = 0;
		  		return ++currentNode;
		  	}

		  	Node newNode;
		  	newNode.isEmpty = 0;
		  	newNode.size = size;

  	

		  	Node remainderNode;
		  	remainderNode.isEmpty = 1;
		  	remainderNode.size = currentNode->size - (size + sizeof(Node));

		  	*currentNode = newNode;

		  	Node * tempNode = currentNode;

		  	currentNode = (char *)currentNode + sizeof(Node) + currentNode->size;
		  	*currentNode = remainderNode;

		  	return ++tempNode;

  		}


		currentNode = (char *)currentNode + sizeof(Node) + currentNode->size;
	}

  	printf("Not enough space for malloc request of %d bytes at file %s line %d\n",size,file,line);
}


void myfree(void* ptr, char* file, int line){

	Node * currentNode = (Node *) mydata;
	Node * leftNode;


	Node * ptrNode = (char *)ptr - sizeof(Node); //find the node and check
	if(ptrNode->size == NULL){
		//not made by mymalloc
		printf("Pointer was not made by malloc at file %s line %d\n",file,line);
	}

	if(ptrNode->isEmpty == 1){
		//already empty cannot free again
		printf("Pointer is already free at file %s line %d\n",file,line);
	}

	ptrNode->isEmpty = 1;




	if(currentNode == ptrNode){
		//there is no left node
		printf("No Left\n");
	}
	else{

		while(currentNode->size != NULL){

			if(((char *)currentNode + (sizeof(Node) + currentNode->size)) == ptrNode){
				//left node found
				leftNode = currentNode;
				//printf("Left Node size is %d\n", leftNode->size);
				break;
			}

			currentNode = (char *)currentNode + sizeof(Node) + currentNode->size;
		}
	}

	Node * rightNode = (char *)ptrNode + sizeof(Node) + ptrNode->size;

	if(leftNode->isEmpty == 1){
		//printf("Merge left\n");
		leftNode->size = leftNode->size + ptrNode->size + sizeof(Node);
		ptrNode = leftNode;
	}

	if(rightNode->isEmpty == 1){
		//printf("Merge right\n");
		ptrNode->size = rightNode->size + ptrNode->size + sizeof(Node);
	}

}







