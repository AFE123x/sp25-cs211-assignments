#include<stdio.h>
#include<stdlib.h>
#include<string.h>

  struct Node{
  	int data;
  	struct Node* next;
  	};
  	

void insert(struct Node** head, int a){
  	
  	struct Node* new= (struct Node*)malloc(sizeof(struct Node));
  	new->data = a;
  	new->next=NULL;
  	if(*head == NULL || (*head)->data>=a){
  		new->next=*head;
  		*head = new;
  		return;
  		}
  	struct Node* something= *head;
  	while(something->next!=NULL && something->next->data < a){
  	something= something-> next;
  	}
  	
  	new->next = something->next;
  	something->next= new;
  	}
  	
  	
  void deleten(struct Node** head, int val)
  {
  struct Node* abc = *head,*prev=NULL;
  
  if(abc!=NULL && abc->data == val)
  {
  	*head=abc->next;
  	free(abc);
  	return;
  	}
  	
  while(abc!= NULL && abc->data != val)
  {
  prev=abc;
  abc=abc->next;}
  if(abc==NULL) return;
  prev->next=abc->next;
  free(abc);
  }
  
  void print(struct Node* head){
  	if(head==NULL){
  	printf("EMPTY\n");
  	return;
  	}
  	struct Node* abc=head;
  	while(abc){
  	printf("%d ", abc->data);
  	abc=abc->next;
  	}
  	printf("\n");
  	}
  	
  void file(const char* filename){
  	

  FILE* file = fopen(filename,"r"); //this will open a file specified by the user.

  if(file == NULL){ //if fopen fails to open the file, it returns NULL
    fprintf(stderr,"%s failed to open",filename);
    exit(1); //exits your program
  }
	struct Node* head=NULL;
  	char insdel[10];
  	int val;
  	
  	while(fscanf(file, "%s %d", insdel, &val)==2){
  	if(strcmp(insdel, "INSERT")==0) insert(&head, val);
  	else if(strcmp(insdel, "DELETE")==0) deleten(&head, val);
  	
  	print(head);
  	}
  	fclose(file);
  	}
  	
  int main(int argc, char* argv[]){
  	if(argc < 2) { //checks if there are 2 arguments!
    fprintf(stderr,"./first {text file}"); //prints messages to stderr. Primarily for error messages
    exit(1); //exits the program with a return code 1.
  }
  	
  	file(argv[1]);
  	return 0;
  	}
  
 
