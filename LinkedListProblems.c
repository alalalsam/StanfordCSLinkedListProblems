#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};



// problems
int Count(struct node* head, int find);
int GetNth(struct node* head, int index);
struct node* DeleteList(struct node** headRef);

// basic utility
int Length(struct node* head);
struct node* BuildOneTwoThree();
void Push(struct node** headRef, int newData);
void ListValues(struct node* head);

// fun tricks
struct node* BuildWithLocalRef();


/************************************************************************************
 * ********************************* Main *******************************************
 * *********************************************************************************/
int main() {
	struct node* list = BuildOneTwoThree();
	Push(&list, 2);
	ListValues(list);
	printf("\n");
	printf("%d %d %d %d", GetNth(list, 0), GetNth(list, 1), GetNth(list, 2), GetNth(list, 3));
	GetNth(list,4);
    return 0;
}


 /************************************************************************************
 * ******************************* Problems ******************************************
 * **********************************************************************************/
// count the number of times a given int occurs in list
int Count(struct node* head, int find ){
	int count = 0;
	struct node* current;
	
	for(current = head; current != NULL; current = current->next){
		if(current->data == find){
			count++;
		}
	}
	return count;
}
 
 
// get data at nth index lmao
int GetNth(struct node* head, int index){
	struct node* current;
	if(head == NULL){printf("\nGetNth head is null\n "); return 0;}
	for(current = head; current != NULL, index != 0; current = current->next, index--){}
	if(current == NULL){printf("\nGetNth index too big :(\n"); return 0;}
	return current->data;
}
 
 
// delete list
struct node* DeleteList(struct node** headRef){
	struct node* current;
	for(current = *headRef; current != NULL; current = *headRef){
		*headRef = current->next;
		free(current);
	}
	return *headRef;
}
	
	
	
/************************************************************************************
 * ***************************** Basic Utility **************************************
 * *********************************************************************************/
// returns length given head pointer
int Length(struct node* head){
    int i = 0;
    struct node* current = head;
    for(current = head; current != NULL; current = current->next, i++){}
    return i;
}


// returns pointer to head of list 3 nodes long. 
struct node* BuildOneTwoThree(){
    struct node* listHead = NULL;
    Push(&listHead, 3);
    Push(&listHead, 2);
	Push(&listHead, 1);
    return listHead;
}


// creates a new node, given a head reference pointer & data.
void Push(struct node** headRef, int newData) {
    struct node* newNode = malloc(sizeof(struct node));
    
    newNode->data = newData;
    newNode->next = *headRef;
    
    *headRef = newNode;
}


//print all values in a list
void ListValues(struct node* head){
	if(head == NULL){printf("ListValues list empty :( \n"); return;}
	struct node* current;
	for(current = head; current != NULL; current = current->next){
		printf("%d ", current->data);
	}
}
	
	
	
/************************************************************************************
 * ******************************* Fun Tricks ***************************************
 * *********************************************************************************/
struct node* BuildWithLocalRef(){
	struct node* head = NULL;
	struct node** ref = &head;
	for(int i = 1; i < 11; i++){
		Push(ref, i);
		ref = &((*ref)->next);      //damn precedence.
	}
	return head;
}
	