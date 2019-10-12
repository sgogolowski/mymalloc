#include "mymalloc.h"
#define METADATA 16


static char mymemory[MAXSIZE];

typedef struct _Node{
	
  int sizeOfBytes;
  int isEmpty;
  struct _Node *next;
}Node;

void splitMemory(Node *, size_t);
Node *findSpace(size_t);
void coalesceMemory();
const int metadata=sizeof(Node);

/*    DEBUGGING LOL
int main(){
  printf("%d\n",MAXSIZE);
  Node head={4080,NULL,1};
  printf("%d\n",sizeof(Node));
  *(Node*)(mymemory+0)=head;
  //printf("ok\n");
  //printf("HELLO WORLD\n%d\n",((Node*)(mymemory+0))->sizeOfBytes);
  //printf("%d\n",((Node*)(mymemory+0))->isEmpty);
  return 0;



}
*/


void myfree(void *ptr, char *filename,int linenum){

}

void* mymalloc(size_t size, char* filename, int linenum){
  if(size>4080)
    printf("You are asking for too much memory at file: %s line %d\n",filename, linenum);		
  Node *availableSpace;
  availableSpace=findSpace(size + metadata);
  if(availableSpace == NULL){
    printf("There is not space available for your %d bytes\n",size);
  }
  else{
    splitMemory(availableSpace, size);
    
    
    
  }




}

void splitMemory(Node *memory,size_t sizeRequested){
  //int offset= &mymemory + metadata + sizeRequested;
  Node *tempptr = memory;
  int freeMemory = (memory->sizeOfBytes) - (sizeRequested + metadata);
  Node reqMem={ sizeRequested,0, memory};
  *(Node*)(memory + sizeRequested + METADATA ) = *memory; 
  *(Node*)(tempptr)=reqMem;
  memory->sizeOfBytes = (memory->sizeOfBytes)-(sizeRequested + metadata);
  memory->isEmpty = 1;
  //memory->isEmpty=1;
  //memory->next=null;
  
  //return &reqMem;
  
}

void coalesceMemory(){
  Node* lastFull, lastEmpty;
  //Node current=



}
//return index of address in mymemory
Node *findSpace(size_t sizeRequested){
  Node *current=(Node*)(mymemory+0);
  while(current != NULL){
  
    if(current->isEmpty==1 && current->sizeOfBytes >= (sizeRequested)){
      return current;
      
    }
  current=current->next;
  }
  return current;


}






