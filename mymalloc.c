#include "mymalloc.h"
#define METADATA 16

typedef struct node{
	
  int sizeOfBytes;
  struct Node* next;
  int isEmpty;
}Node;
Node head=;
head->sizeOfBytes=4080;
head->next=NULL;
head-> isEmpty=1;
(Node*)(mymemory[0])=head;

int main(){

	printf("%d\n",mymemory[0]->sizeOfBytes);
	return 0;



}

void* mymalloc(size_t size, __FILE__, __LINE__){
  if(size>4080)
    printf("You are asking for too much memory at file: %s line %d\n",__FILE__,__LINE__);		
  int  availableSpace=findSpace(size);
  if(availableSpace == NULL){
    printf("There is not space available for your %d bytes\n",size);
  }
  else{
    splitMemory(availableSpace, size);
    
    
    
  }




}

int splitMemory(Node* memory,size_t sizeRequested){
  
  int freeMemory = (memory->sizeOfBytes) - sizeRequested;
  Node reqMem={
    sizeOfBytes=sizeRequested;
    isEmpty=0;
    next=memory;
  }
  (Node*)(&memory)=reqMem;
  (Node*)((&memory)+ reqMem.sizeOfBytes + METADATA ) = memory; 
  memory->sizeOfBytes = (memory->sizeOfBytes)-sizeRequested;
  
  memory->isEmpty=1;
  memory->next=null;
  
  return &reqMem;
  
}

void coalesceMemory(){
  Node* lastFull, lastEmpty;
  //Node current=



}
//return index of address in mymemory
Node* findSpace(size_t sizeRequested){
  Node* current=mymemory[0];
  while(current != NULL){
  
    if(current->isEmpty==0 && current->sizeOfBytes >= (sizeRequested + 16)){
      return current;
      
    }
  current=current->next;
  }
  return NULL;


}






