#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mymalloc.h"

void printNodes();

typedef struct node{
	
  int size;
  int isEmpty;
  //struct Node* next;
}Node;






int main(int argc, char ** argv){

	//Puts the header node into the start of the array
	// Node * saveHead = (Node *) mydata;
	// Node headNode;
	// headNode.isEmpty = 1;
	// headNode.size = 30;
	// //headNode.size = sizeof(mydata) - sizeof(Node); //size of the rest of the data array
	// *saveHead = headNode;

	



// Node * secNode;
// secNode->isEmpty = 1;
// secNode->size = 20;
// secNode->next = NULL;

// size_t move = sizeof(Node) + headNode.size;
// saveHead = (char *)saveHead + move;

// *saveHead = *secNode;


// headNode.next = saveHead;




//printf("Save Addr %x\n",saveHead);


	char * file;
	int line;

  printf("Testing\n");
  char * tester0 = (char *) malloc(sizeof(char) *10);
  char * tester1 = (char *) malloc(sizeof(char) *30);
  char * tester2 = (char *) malloc(sizeof(char) *40);
  char * tester3 = (char *) malloc(sizeof(char) *10);

  //char * tester3 = (char *) malloc(sizeof(char) *4088);

  strcpy(tester1,"abc");

  free(tester1);
  free(tester1);

  char * tester4 = (char *) malloc(sizeof(char) *30);
  //strcpy(tester4,"ten");

  printNodes();


  printf("Tester %s\n", tester4);



}

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

	    printf("Empty Data, create Header Node\n");

	    Node headNode;
	    headNode.isEmpty = 1;
	    headNode.size = sizeof(mydata) - sizeof(Node); //size of the rest of the data array
	    //headNode.next = NULL;
	    *currentNode = headNode;


  	}
	
	//Loops through each node
	while(currentNode->size != NULL){

		if(currentNode->isEmpty == 1 && currentNode->size == size){

		  	//Great nothing much is needed

		  	printf("great\n");
		  	currentNode->isEmpty = 0;
		  	return ++currentNode;

	  	}

  		if(currentNode->isEmpty == 1 && currentNode->size > size){

	  		//A split is Needed

		  	//check if there is enough remaining
		  	if(currentNode->size - size <= sizeof(Node)){
		  		//no split

		  		printf("No room for a split\n");
		  		currentNode->isEmpty = 0;
		  		return ++currentNode;
		  	}

	  		printf("split\n");

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

  	printf("Not enough space\n");
}


void myfree(void* ptr, char* file, int line){

	Node * currentNode = (Node *) mydata;
	Node * leftNode;


	Node * ptrNode = (char *)ptr - sizeof(Node); //find the node and check
	if(ptrNode->size == NULL){
		//not made by mymalloc
		printf("Not made by malloc\n");
	}

	if(ptrNode->isEmpty == 1){
		//already empty cannot free again
		printf("Already Free\n");
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
				printf("Left Node size is %d\n", leftNode->size);
				break;
			}

			currentNode = (char *)currentNode + sizeof(Node) + currentNode->size;
		}
	}

	Node * rightNode = (char *)ptrNode + sizeof(Node) + ptrNode->size;

	if(leftNode->isEmpty == 1){
		printf("Merge left\n");
		leftNode->size = leftNode->size + ptrNode->size + sizeof(Node);
		ptrNode = leftNode;
	}

	if(rightNode->isEmpty == 1){
		printf("Merge right\n");
		ptrNode->size = rightNode->size + ptrNode->size + sizeof(Node);
	}

}


// void splitMemory(Node* memory,size_t sizeRequested){
//   Node* freeMem={
//     sizeOfBytes=(memory->sizeOfBytes)-sizeRequested;
//     isEmpty=1;
//     next=memory->next->next;
//   }
//   memory->sizeOfBytes=sizeRequested;
//   memory->isEmpty=0;
//   memory->next=freeMem;
  
  
  
// }

// void coalesceMemory(){
//   Node* lastFull, lastEmpty;
//   Node current=



// }

// Node* findSpace(size_t sizeRequested){
//   Node* current=Node;
//   while(current != NULL){
  
//     if(current->isEmpty==0 && current->sizeOfBytes >= (sizeRequested + 16)){
//       return current;
      
//     }
//   current=current->next;
//   }
//   return NULL;


// }






