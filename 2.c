//double linked list all insert and delete operation
#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head, *temp;
static int count=0;

void create();
void display();
void insert_begin();
void insert_end();
void insert_atPos();
void delete_begin();
void delete_end();
void delete_atPos();

int main(){
	
	create();
	int i;
	
	printf("\nCHOICES:\n1 for displaying the list\n2 for insert at begin\n3 for insert at end"
	"\n4 for insert at given position\n5 for delete at begin\n6 for delete at end"
	"\n7 for delete at given position\n8 for exit\n\n");
	
	int again=1;
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				display();
				break;	
			case 2:
				insert_begin();
				break;
			case 3:
				insert_end();
				break;
			case 4:
				insert_atPos();
				break;
			case 5:
				delete_begin();
				break;
			case 6:
				delete_end();
				break;
			case 7:
				delete_atPos();
				break;
			case 8:
				again=0;
				break;
			default:
				printf("\nWrong Input!");
		}
	}while(again==1);
	
	return 0;
}

void create(){
	printf("Create the list....\n\n");
	struct node *newnode;
	int again=1;
	do{
		count++;
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter a data: ");
		scanf("%d", &newnode->data);
		if(head==NULL){
			head=newnode;
			temp=newnode;
			newnode->prev=NULL;
			newnode->next=NULL;
		}
		else{
			newnode->prev=temp;
			newnode->next=NULL;
			temp->next=newnode;
			temp=newnode;
		}
		printf("To continue press 1 else 0 : ");
		scanf("%d", &again);
		}while(again!=0);
	
}

void display(){
	temp=head;
	printf("\nThe list is: \n");
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void insert_begin(){
	temp=head;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter an element to insert at begin: ");
	scanf("%d", &newnode->data);
	temp->prev=newnode;
	newnode->next=temp;
	newnode->prev=NULL;
	head=newnode;
	count++;
}

void insert_end(){
	temp=head;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter an element to insert at end: ");
	scanf("%d", &newnode->data);
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next=NULL;
	count++;
}

void insert_atPos(){
	temp=head;
	int pos,curr=1;
	printf("\nEnter the position at which you want to enter an element: ");
	scanf("%d", &pos);
	int flag=0;
	while(flag==0){
		if(pos==1){
		insert_begin();
		flag=1;
		}
		else if(pos==count+1){
			insert_end();
			flag=1;
		}
		else if(pos>1 && pos <=count){
			while(curr<pos &&temp!=NULL){
				curr++;
				temp=temp->next;
			}
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter the element to be inserted: ");
		scanf("%d", &newnode->data);
		newnode->next=temp;
		newnode->prev=temp->prev;
		temp->prev->next=newnode;
		temp->prev=newnode;
		count++;
		flag=1;
		}
		else if(pos<1 || pos>count+1){
		printf("Wrong Position! Please Enter a correct position: ");
		scanf("%d", &pos);
		flag=0;
		}
	}		
}

void delete_begin(){
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
	count--;
}

void delete_end(){
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
	count--;
}

void delete_atPos(){
	temp=head;
	int pos,curr=1;
	printf("\nEnter the position at which you want to delete an element: ");
	scanf("%d", &pos);
	int flag=0;
	while(flag==0){
		if(pos==1){
		delete_begin();
		flag=1;
		}
		else if(pos==count){
			delete_end();
			flag=1;
		}
		else if(pos>1 && pos <count){
			while(curr<pos && temp!=NULL){
				curr++;
				temp=temp->next;
			}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		flag=1;
		count--;
		}
		else if(pos<1 || pos>count){
		printf("Wrong Position! Please Enter a correct position: ");
		scanf("%d", &pos);
		flag=0;
		}
	}
}	

