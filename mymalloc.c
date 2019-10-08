#include <stdio.h>
#include <stdlib.h>
#include "MYMALLOC_H.h"


typedef struct node{
	
  int sizeOfBytes;
  struct Node* next;
  int isEmpty;
}Node;
Node* head;
head->sizeOfBytes=4080;
head->next=NULL;
head-> isEmpty=1;
testing branches and merging
void* mymalloc(size_t size, __FILE__, __LINE__){
  if(size>4080)
    printf("You are asking for too much memory at file: %s line %d\n",__FILE__,__LINE__);		
  Node* availableSpace=findSpace(size);
  if(availableSpace == NULL){
    printf("There is not space available for your %d bytes\n",size);
  }
  else{
    splitMemory(availableSpace);
    
    
    
  }




}

void splitMemory(Node* memory,size_t sizeRequested){
  Node* freeMem={
    sizeOfBytes=(memory->sizeOfBytes)-sizeRequested;
    isEmpty=1;
    next=memory->next->next;
  }
  memory->sizeOfBytes=sizeRequested;
  memory->isEmpty=0;
  memory->next=freeMem;
  
  
  
}

void coalesceMemory(){
  Node* lastFull, lastEmpty;
  Node current=



}

Node* findSpace(size_t sizeRequested){
  Node* current=Node;
  while(current != NULL){
  
    if(current->isEmpty==0 && current->sizeOfBytes >= (sizeRequested + 16)){
      return current;
      
    }
  current=current->next;
  }
  return NULL;


}






